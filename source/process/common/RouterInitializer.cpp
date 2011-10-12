/**
 * @file process/RouterInitializer.cpp
 * @date Created <2011-09-29 18:57:25>
 *
 * This file is generated by generators/router_initializer.rb from config file
 * generators/router_initializer.yml. Do not edit this file directly. Please read
 * the config file, update options there and re-run the ruby script to
 * update this file.
 */

#include "RouterInitializer.h"
#include <util/driver/ActionHandler.h>

#include <memory> // for std::auto_ptr

#include "controllers/AutoFillController.h"
#include "controllers/CommandsController.h"
#include "controllers/KeywordsController.h"
#include "controllers/DocumentsController.h"
#include "controllers/TestController.h"
#include "controllers/StatusController.h"
#include "controllers/LogAnalysisController.h"
#include "controllers/FacetedController.h"
#include "controllers/QueryCorrectionController.h"
#include "mining/QueryLogSearchService.h"
#include "controllers/TopicController.h"
#include "controllers/RecommendController.h"
#include "controllers/ServiceController.h"
#include "controllers/EcController.h"

namespace sf1r
{

void initializeDriverRouter(::izenelib::driver::Router& router, IService* service, bool enableTest)
{
    {
        FacetedController faceted;
        const std::string controllerName("faceted");
        typedef ::izenelib::driver::ActionHandler<FacetedController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr clickHandler(
            new handler_type(
                faceted,
                &FacetedController::click
            )
        );

        router.map(
            controllerName,
            "click",
            clickHandler.get()
        );
        clickHandler.release();

        handler_ptr get_ontologyHandler(
            new handler_type(
                faceted,
                &FacetedController::get_ontology
            )
        );

        router.map(
            controllerName,
            "get_ontology",
            get_ontologyHandler.get()
        );
        get_ontologyHandler.release();

        handler_ptr get_repHandler(
            new handler_type(
                faceted,
                &FacetedController::get_rep
            )
        );

        router.map(
            controllerName,
            "get_rep",
            get_repHandler.get()
        );
        get_repHandler.release();

        handler_ptr get_static_repHandler(
            new handler_type(
                faceted,
                &FacetedController::get_static_rep
            )
        );

        router.map(
            controllerName,
            "get_static_rep",
            get_static_repHandler.get()
        );
        get_static_repHandler.release();

        handler_ptr manmadeHandler(
            new handler_type(
                faceted,
                &FacetedController::manmade
            )
        );

        router.map(
            controllerName,
            "manmade",
            manmadeHandler.get()
        );
        manmadeHandler.release();

        handler_ptr set_ontologyHandler(
            new handler_type(
                faceted,
                &FacetedController::set_ontology
            )
        );

        router.map(
            controllerName,
            "set_ontology",
            set_ontologyHandler.get()
        );
        set_ontologyHandler.release();

        handler_ptr static_clickHandler(
            new handler_type(
                faceted,
                &FacetedController::static_click
            )
        );

        router.map(
            controllerName,
            "static_click",
            static_clickHandler.get()
        );
        static_clickHandler.release();
    }

    {
        QueryCorrectionController query_correction;
        const std::string controllerName("query_correction");
        typedef ::izenelib::driver::ActionHandler<QueryCorrectionController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;
        query_correction.setService(static_cast<QueryLogSearchService*>(service));

        handler_ptr indexHandler(
            new handler_type(
                query_correction,
                &QueryCorrectionController::index
            )
        );

        router.map(
            controllerName,
            "index",
            indexHandler.get()
        );
        indexHandler.release();
    }

    {
        RecommendController recommend;
        const std::string controllerName("recommend");
        typedef ::izenelib::driver::ActionHandler<RecommendController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr add_itemHandler(
            new handler_type(
                recommend,
                &RecommendController::add_item
            )
        );

        router.map(
            controllerName,
            "add_item",
            add_itemHandler.get()
        );
        add_itemHandler.release();

        handler_ptr add_userHandler(
            new handler_type(
                recommend,
                &RecommendController::add_user
            )
        );

        router.map(
            controllerName,
            "add_user",
            add_userHandler.get()
        );
        add_userHandler.release();

        handler_ptr do_recommendHandler(
            new handler_type(
                recommend,
                &RecommendController::do_recommend
            )
        );

        router.map(
            controllerName,
            "do_recommend",
            do_recommendHandler.get()
        );
        do_recommendHandler.release();

        handler_ptr get_itemHandler(
            new handler_type(
                recommend,
                &RecommendController::get_item
            )
        );

        router.map(
            controllerName,
            "get_item",
            get_itemHandler.get()
        );
        get_itemHandler.release();

        handler_ptr get_userHandler(
            new handler_type(
                recommend,
                &RecommendController::get_user
            )
        );

        router.map(
            controllerName,
            "get_user",
            get_userHandler.get()
        );
        get_userHandler.release();

        handler_ptr purchase_itemHandler(
            new handler_type(
                recommend,
                &RecommendController::purchase_item
            )
        );

        router.map(
            controllerName,
            "purchase_item",
            purchase_itemHandler.get()
        );
        purchase_itemHandler.release();

        handler_ptr remove_itemHandler(
            new handler_type(
                recommend,
                &RecommendController::remove_item
            )
        );

        router.map(
            controllerName,
            "remove_item",
            remove_itemHandler.get()
        );
        remove_itemHandler.release();

        handler_ptr remove_userHandler(
            new handler_type(
                recommend,
                &RecommendController::remove_user
            )
        );

        router.map(
            controllerName,
            "remove_user",
            remove_userHandler.get()
        );
        remove_userHandler.release();

        handler_ptr top_item_bundleHandler(
            new handler_type(
                recommend,
                &RecommendController::top_item_bundle
            )
        );

        router.map(
            controllerName,
            "top_item_bundle",
            top_item_bundleHandler.get()
        );
        top_item_bundleHandler.release();

        handler_ptr track_eventHandler(
            new handler_type(
                recommend,
                &RecommendController::track_event
            )
        );

        router.map(
            controllerName,
            "track_event",
            track_eventHandler.get()
        );
        track_eventHandler.release();

        handler_ptr update_itemHandler(
            new handler_type(
                recommend,
                &RecommendController::update_item
            )
        );

        router.map(
            controllerName,
            "update_item",
            update_itemHandler.get()
        );
        update_itemHandler.release();

        handler_ptr update_shopping_cartHandler(
            new handler_type(
                recommend,
                &RecommendController::update_shopping_cart
            )
        );

        router.map(
            controllerName,
            "update_shopping_cart",
            update_shopping_cartHandler.get()
        );
        update_shopping_cartHandler.release();

        handler_ptr update_userHandler(
            new handler_type(
                recommend,
                &RecommendController::update_user
            )
        );

        router.map(
            controllerName,
            "update_user",
            update_userHandler.get()
        );
        update_userHandler.release();

        handler_ptr visit_itemHandler(
            new handler_type(
                recommend,
                &RecommendController::visit_item
            )
        );

        router.map(
            controllerName,
            "visit_item",
            visit_itemHandler.get()
        );
        visit_itemHandler.release();
    }

    {
        TopicController topic;
        const std::string controllerName("topic");
        typedef ::izenelib::driver::ActionHandler<TopicController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr get_in_date_rangeHandler(
            new handler_type(
                topic,
                &TopicController::get_in_date_range
            )
        );

        router.map(
            controllerName,
            "get_in_date_range",
            get_in_date_rangeHandler.get()
        );
        get_in_date_rangeHandler.release();

        handler_ptr get_similarHandler(
            new handler_type(
                topic,
                &TopicController::get_similar
            )
        );

        router.map(
            controllerName,
            "get_similar",
            get_similarHandler.get()
        );
        get_similarHandler.release();

        handler_ptr get_temporal_similarHandler(
            new handler_type(
                topic,
                &TopicController::get_temporal_similar
            )
        );

        router.map(
            controllerName,
            "get_temporal_similar",
            get_temporal_similarHandler.get()
        );
        get_temporal_similarHandler.release();
    }

    {
        AutoFillController auto_fill;
        const std::string controllerName("auto_fill");
        typedef ::izenelib::driver::ActionHandler<AutoFillController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr indexHandler(
            new handler_type(
                auto_fill,
                &AutoFillController::index
            )
        );

        router.map(
            controllerName,
            "index",
            indexHandler.get()
        );
        indexHandler.release();
    }

    {
        EcController ec;
        const std::string controllerName("ec");
        typedef ::izenelib::driver::ActionHandler<EcController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr add_docs_to_tidHandler(
            new handler_type(
                ec,
                &EcController::add_docs_to_tid
            )
        );

        router.map(
            controllerName,
            "add_docs_to_tid",
            add_docs_to_tidHandler.get()
        );
        add_docs_to_tidHandler.release();

        handler_ptr add_new_tidHandler(
            new handler_type(
                ec,
                &EcController::add_new_tid
            )
        );

        router.map(
            controllerName,
            "add_new_tid",
            add_new_tidHandler.get()
        );
        add_new_tidHandler.release();

        handler_ptr get_all_product_infoHandler(
            new handler_type(
                ec,
                &EcController::get_all_product_info
            )
        );

        router.map(
            controllerName,
            "get_all_product_info",
            get_all_product_infoHandler.get()
        );
        get_all_product_infoHandler.release();

        handler_ptr get_all_tidHandler(
            new handler_type(
                ec,
                &EcController::get_all_tid
            )
        );

        router.map(
            controllerName,
            "get_all_tid",
            get_all_tidHandler.get()
        );
        get_all_tidHandler.release();

        handler_ptr get_docs_by_tidHandler(
            new handler_type(
                ec,
                &EcController::get_docs_by_tid
            )
        );

        router.map(
            controllerName,
            "get_docs_by_tid",
            get_docs_by_tidHandler.get()
        );
        get_docs_by_tidHandler.release();

        handler_ptr get_tids_by_docsHandler(
            new handler_type(
                ec,
                &EcController::get_tids_by_docs
            )
        );

        router.map(
            controllerName,
            "get_tids_by_docs",
            get_tids_by_docsHandler.get()
        );
        get_tids_by_docsHandler.release();

        handler_ptr remove_docs_from_tidHandler(
            new handler_type(
                ec,
                &EcController::remove_docs_from_tid
            )
        );

        router.map(
            controllerName,
            "remove_docs_from_tid",
            remove_docs_from_tidHandler.get()
        );
        remove_docs_from_tidHandler.release();
    }

    {
        CommandsController commands;
        const std::string controllerName("commands");
        typedef ::izenelib::driver::ActionHandler<CommandsController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr indexHandler(
            new handler_type(
                commands,
                &CommandsController::index
            )
        );

        router.map(
            controllerName,
            "index",
            indexHandler.get()
        );
        indexHandler.release();

        handler_ptr index_query_logHandler(
            new handler_type(
                commands,
                &CommandsController::index_query_log
            )
        );

        router.map(
            controllerName,
            "index_query_log",
            index_query_logHandler.get()
        );
        index_query_logHandler.release();

        handler_ptr index_recommendHandler(
            new handler_type(
                commands,
                &CommandsController::index_recommend
            )
        );

        router.map(
            controllerName,
            "index_recommend",
            index_recommendHandler.get()
        );
        index_recommendHandler.release();

        handler_ptr optimize_indexHandler(
            new handler_type(
                commands,
                &CommandsController::optimize_index
            )
        );

        router.map(
            controllerName,
            "optimize_index",
            optimize_indexHandler.get()
        );
        optimize_indexHandler.release();
    }

    if (enableTest)
    {
        TestController test;
        const std::string controllerName("test");
        typedef ::izenelib::driver::ActionHandler<TestController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr echoHandler(
            new handler_type(
                test,
                &TestController::echo
            )
        );

        router.map(
            controllerName,
            "echo",
            echoHandler.get()
        );
        echoHandler.release();

        handler_ptr sleepHandler(
            new handler_type(
                test,
                &TestController::sleep
            )
        );

        router.map(
            controllerName,
            "sleep",
            sleepHandler.get()
        );
        sleepHandler.release();
    }

    {
        StatusController status;
        const std::string controllerName("status");
        typedef ::izenelib::driver::ActionHandler<StatusController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr indexHandler(
            new handler_type(
                status,
                &StatusController::index
            )
        );

        router.map(
            controllerName,
            "index",
            indexHandler.get()
        );
        indexHandler.release();
    }

    {
        DocumentsController documents;
        const std::string controllerName("documents");
        typedef ::izenelib::driver::ActionHandler<DocumentsController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr createHandler(
            new handler_type(
                documents,
                &DocumentsController::create
            )
        );

        router.map(
            controllerName,
            "create",
            createHandler.get()
        );
        createHandler.release();

        handler_ptr destroyHandler(
            new handler_type(
                documents,
                &DocumentsController::destroy
            )
        );

        router.map(
            controllerName,
            "destroy",
            destroyHandler.get()
        );
        destroyHandler.release();

        handler_ptr duplicate_withHandler(
            new handler_type(
                documents,
                &DocumentsController::duplicate_with
            )
        );

        router.map(
            controllerName,
            "duplicate_with",
            duplicate_withHandler.get()
        );
        duplicate_withHandler.release();

        handler_ptr getHandler(
            new handler_type(
                documents,
                &DocumentsController::get
            )
        );

        router.map(
            controllerName,
            "get",
            getHandler.get()
        );
        getHandler.release();

        handler_ptr get_freq_group_labelsHandler(
            new handler_type(
                documents,
                &DocumentsController::get_freq_group_labels
            )
        );

        router.map(
            controllerName,
            "get_freq_group_labels",
            get_freq_group_labelsHandler.get()
        );
        get_freq_group_labelsHandler.release();

        handler_ptr get_topicHandler(
            new handler_type(
                documents,
                &DocumentsController::get_topic
            )
        );

        router.map(
            controllerName,
            "get_topic",
            get_topicHandler.get()
        );
        get_topicHandler.release();

        handler_ptr get_topic_with_simHandler(
            new handler_type(
                documents,
                &DocumentsController::get_topic_with_sim
            )
        );

        router.map(
            controllerName,
            "get_topic_with_sim",
            get_topic_with_simHandler.get()
        );
        get_topic_with_simHandler.release();

        handler_ptr indexHandler(
            new handler_type(
                documents,
                &DocumentsController::index
            )
        );

        router.map(
            controllerName,
            "index",
            indexHandler.get()
        );
        indexHandler.release();

        handler_ptr searchHandler(
            new handler_type(
                documents,
                &DocumentsController::search
            )
        );

        router.map(
            controllerName,
            "search",
            searchHandler.get()
        );
        searchHandler.release();

        handler_ptr set_top_group_labelHandler(
            new handler_type(
                documents,
                &DocumentsController::set_top_group_label
            )
        );

        router.map(
            controllerName,
            "set_top_group_label",
            set_top_group_labelHandler.get()
        );
        set_top_group_labelHandler.release();

        handler_ptr similar_toHandler(
            new handler_type(
                documents,
                &DocumentsController::similar_to
            )
        );

        router.map(
            controllerName,
            "similar_to",
            similar_toHandler.get()
        );
        similar_toHandler.release();

        handler_ptr similar_to_imageHandler(
            new handler_type(
                documents,
                &DocumentsController::similar_to_image
            )
        );

        router.map(
            controllerName,
            "similar_to_image",
            similar_to_imageHandler.get()
        );
        similar_to_imageHandler.release();

        handler_ptr updateHandler(
            new handler_type(
                documents,
                &DocumentsController::update
            )
        );

        router.map(
            controllerName,
            "update",
            updateHandler.get()
        );
        updateHandler.release();

        handler_ptr visitHandler(
            new handler_type(
                documents,
                &DocumentsController::visit
            )
        );

        router.map(
            controllerName,
            "visit",
            visitHandler.get()
        );
        visitHandler.release();
    }

    {
        LogAnalysisController log_analysis;
        const std::string controllerName("log_analysis");
        typedef ::izenelib::driver::ActionHandler<LogAnalysisController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr delete_databaseHandler(
            new handler_type(
                log_analysis,
                &LogAnalysisController::delete_database
            )
        );

        router.map(
            controllerName,
            "delete_database",
            delete_databaseHandler.get()
        );
        delete_databaseHandler.release();

        handler_ptr delete_record_from_system_eventsHandler(
            new handler_type(
                log_analysis,
                &LogAnalysisController::delete_record_from_system_events
            )
        );

        router.map(
            controllerName,
            "delete_record_from_system_events",
            delete_record_from_system_eventsHandler.get()
        );
        delete_record_from_system_eventsHandler.release();

        handler_ptr delete_record_from_user_queriesHandler(
            new handler_type(
                log_analysis,
                &LogAnalysisController::delete_record_from_user_queries
            )
        );

        router.map(
            controllerName,
            "delete_record_from_user_queries",
            delete_record_from_user_queriesHandler.get()
        );
        delete_record_from_user_queriesHandler.release();

        handler_ptr inject_user_queriesHandler(
            new handler_type(
                log_analysis,
                &LogAnalysisController::inject_user_queries
            )
        );

        router.map(
            controllerName,
            "inject_user_queries",
            inject_user_queriesHandler.get()
        );
        inject_user_queriesHandler.release();

        handler_ptr merchant_countHandler(
            new handler_type(
                log_analysis,
                &LogAnalysisController::merchant_count
            )
        );

        router.map(
            controllerName,
            "merchant_count",
            merchant_countHandler.get()
        );
        merchant_countHandler.release();

        handler_ptr product_update_infoHandler(
            new handler_type(
                log_analysis,
                &LogAnalysisController::product_update_info
            )
        );

        router.map(
            controllerName,
            "product_update_info",
            product_update_infoHandler.get()
        );
        product_update_infoHandler.release();

        handler_ptr system_eventsHandler(
            new handler_type(
                log_analysis,
                &LogAnalysisController::system_events
            )
        );

        router.map(
            controllerName,
            "system_events",
            system_eventsHandler.get()
        );
        system_eventsHandler.release();

        handler_ptr user_queriesHandler(
            new handler_type(
                log_analysis,
                &LogAnalysisController::user_queries
            )
        );

        router.map(
            controllerName,
            "user_queries",
            user_queriesHandler.get()
        );
        user_queriesHandler.release();
    }

    {
        KeywordsController keywords;
        const std::string controllerName("keywords");
        typedef ::izenelib::driver::ActionHandler<KeywordsController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr indexHandler(
            new handler_type(
                keywords,
                &KeywordsController::index
            )
        );

        router.map(
            controllerName,
            "index",
            indexHandler.get()
        );
        indexHandler.release();

        handler_ptr inject_query_correctionHandler(
            new handler_type(
                keywords,
                &KeywordsController::inject_query_correction
            )
        );

        router.map(
            controllerName,
            "inject_query_correction",
            inject_query_correctionHandler.get()
        );
        inject_query_correctionHandler.release();

        handler_ptr inject_query_recommendHandler(
            new handler_type(
                keywords,
                &KeywordsController::inject_query_recommend
            )
        );

        router.map(
            controllerName,
            "inject_query_recommend",
            inject_query_recommendHandler.get()
        );
        inject_query_recommendHandler.release();
    }

    {
        ServiceController service;
        const std::string controllerName("service");
        typedef ::izenelib::driver::ActionHandler<ServiceController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr process_overdueHandler(
            new handler_type(
                service,
                &ServiceController::process_overdue
            )
        );

        router.map(
            controllerName,
            "process_overdue",
            process_overdueHandler.get()
        );
        process_overdueHandler.release();

        handler_ptr renewHandler(
            new handler_type(
                service,
                &ServiceController::renew
            )
        );

        router.map(
            controllerName,
            "renew",
            renewHandler.get()
        );
        renewHandler.release();
    }

}

} // namespace sf1r

