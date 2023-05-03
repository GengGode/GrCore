//
// Created by YuSuiXian on 2023/5/3.
//

#ifndef GRCORE_HANDLE_H
#define GRCORE_HANDLE_H

// src
#ifndef GRCORE_RESULT_INCLUDE
#define GRCORE_RESULT_INCLUDE
#include "grcore.result.h"
#endif

// std
#ifndef STD_MAP_INCLUDE
#define STD_MAP_INCLUDE
#include <map>
#endif
#ifndef STD_VECTOR_INCLUDE
#define STD_VECTOR_INCLUDE
#include <vector>
#endif
#ifndef STD_MEMORY_INCLUDE
#define STD_MEMORY_INCLUDE
#include <memory>
#endif
#ifndef STD_STRING_INCLUDE
#define STD_STRING_INCLUDE
#include <string>
#endif



namespace Gr {
    namespace Core {
        // define type
        class Flow;
        class Task;

        class Handle {
        public:
            Handle();
            ~Handle();
        public:
            // flow
            Res<bool>                     insert_flow(const std::string& flow_name, const std::shared_ptr<Flow>& flow);
            Res<bool>                     remove_flow(const std::string& flow_name);
            Res<std::shared_ptr<Flow>>    find_flow(const std::string& flow_name);
            Res<std::vector<std::string>> get_flow_names();
            // task
            Res<bool>                     start_task_from_flow(const std::string& flow_name, const std::string& task_name);
            Res<bool>                     stop_task(const std::string& flow_name, const std::string& task_name);
            Res<std::shared_ptr<Task>>    find_task(const std::string& task_name);
            Res<std::vector<std::string>> get_task_names();

        private:
            std::map<std::string, std::shared_ptr<Flow>> m_flow_map;
            std::map<std::string, std::shared_ptr<Task>> m_task_map;
        };

    } // Gr
} // Core

#endif //GRCORE_HANDLE_H
