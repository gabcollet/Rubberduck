/* *************************************************************************** */
/*                 *#########                                                  */
/*                ##........../##           KWAK!                              */
/*              *#,.......,##....#######  /                                    */
/*              ##........./....##////##                                       */
/*    ##          ##...........,##((##                                         */
/*   #.###/        ##,..........*                                              */
/*  #(.....(######(###*........,##                                             */
/* ##.............................##      File    : log.hpp                    */
/* ##.    __       __  o       __  ##                                          */
/* ##.   |_  |\ | | __ | |\ | |_    *#.   Created : Gabcollet                  */
/*  ##   |__ | \| |__| | | \| |__   ,#,             2022/06/16                 */
/*   ##.............................##                                         */
/*    /##........................*##      Updated : Gabcollet                  */
/*       ###/................*###.                  2022/06/16                 */
/*            ##############.                                                  */
/* *************************************************************************** */

#ifndef LOG_HPP
#define LOG_HPP

#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

// Core log macros
#define RUBBERDUCK_CORE_TRACE(...)   ::Rubberduck::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RUBBERDUCK_CORE_INFO(...)    ::Rubberduck::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RUBBERDUCK_CORE_WARN(...)    ::Rubberduck::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RUBBERDUCK_CORE_ERROR(...)   ::Rubberduck::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RUBBERDUCK_CORE_CRITICAL(...)   ::Rubberduck::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros 
#define RUBBERDUCK_TRACE(...)   ::Rubberduck::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RUBBERDUCK_INFO(...)    ::Rubberduck::Log::GetClientLogger()->info(__VA_ARGS__)
#define RUBBERDUCK_WARN(...)    ::Rubberduck::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RUBBERDUCK_ERROR(...)   ::Rubberduck::Log::GetClientLogger()->error(__VA_ARGS__)
#define RUBBERDUCK_CRITICAL(...)   ::Rubberduck::Log::GetClientLogger()->critical(__VA_ARGS__)

namespace Rubberduck {

    class Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }


    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

#endif