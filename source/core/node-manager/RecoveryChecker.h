#ifndef SF1R_NODEMANAGER_RECOVERCHECKER_H
#define SF1R_NODEMANAGER_RECOVERCHECKER_H

#include "RequestLog.h"
#include <string>
#include <configuration-manager/CollectionPath.h>
#include <util/singleton.h>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>

namespace sf1r
{

class ReqLogMgr;
class SF1Config;
class RecoveryChecker
{
public:
    typedef boost::function<bool(const std::string&, const std::string&, bool)> StartColCBFuncT;
    typedef boost::function<bool(const std::string&, bool)> StopColCBFuncT;
    typedef boost::function<void(const std::string&)> FlushColCBFuncT;
    typedef boost::function<bool(const std::string&)> ReopenColCBFuncT;

    static RecoveryChecker* get()
    {
        return ::izenelib::util::Singleton<RecoveryChecker>::get();
    }

    static void forceExit(const std::string& err = "");
    static void clearForceExitFlag();
    static bool isLastNormalExit();

    //RecoveryChecker(const CollectionPath& colpath);
    bool backup();
    bool setRollbackFlag(uint32_t inc_id);
    void clearRollbackFlag();
    bool rollbackLastFail(bool need_restore_backupfile = true);
    bool checkAndRestoreBackupFile(const CollectionPath& colpath);
    bool checkDataConsistent();
    bool hasAnyBackup();
    void flushAllData();

    void setRestartCallback(StartColCBFuncT start_col, StopColCBFuncT stop_col)
    {
        start_col_ = start_col;
        stop_col_ = stop_col;
    }

    void setColCallback(ReopenColCBFuncT reopen_cb, FlushColCBFuncT flush_cb)
    {
        reopen_col_ = reopen_cb;
        flush_col_ = flush_cb;
    }

    void init(const std::string& conf_dir, const std::string& workdir);
    void addCollection(const std::string& colname, const CollectionPath& colpath, const std::string& configfile);
    void removeCollection(const std::string& colname);
    bool getCollPath(const std::string& colname, CollectionPath& colpath);
    void getCollList(std::vector<std::string>& coll_list);

    //void updateCollection(const SF1Config& sf1_config);
    boost::shared_ptr<ReqLogMgr> getReqLogMgr()
    {
        return reqlog_mgr_;
    }
    void onRecoverCallback(bool startup = true);
    void onRecoverWaitPrimaryCallback();
    void onRecoverWaitReplicasCallback();
private:
    typedef std::map<std::string, std::pair<CollectionPath, std::string> > CollInfoMapT;
    static void setForceExitFlag();
    bool backupColl(const CollectionPath& colpath, const bfs::path& dest_path);
    void syncToNewestReqLog();
    void syncSCDFiles();
    bool redoLog(ReqLogMgr* redolog, uint32_t start_id);
    std::map<std::string, std::string> handleConfigUpdate();
    bool updateConfigFromLog(const std::string& packed_data);
    StartColCBFuncT start_col_;
    StopColCBFuncT stop_col_;
    ReopenColCBFuncT reopen_col_;
    FlushColCBFuncT flush_col_;
    std::string backup_basepath_;
    std::string request_log_basepath_;
    std::string redo_log_basepath_;
    std::string rollback_file_;
    std::string last_conf_file_;
    std::string configDir_;
    boost::shared_ptr<ReqLogMgr> reqlog_mgr_;
    CollInfoMapT all_col_info_;
    boost::mutex mutex_;
};

}

#endif
