/* *************************************************************************** */
/*                 *#########                                                  */
/*                ##........../##           KWAK!                              */
/*              *#,.......,##....#######  /                                    */
/*              ##........./....##////##                                       */
/*    ##          ##...........,##((##                                         */
/*   #.###/        ##,..........*                                              */
/*  #(.....(######(###*........,##                                             */
/* ##.............................##      File    : core.hpp                   */
/* ##.    __       __  o       __  ##                                          */
/* ##.   |_  |\ | | __ | |\ | |_    *#.   Created : Gabcollet                  */
/*  ##   |__ | \| |__| | | \| |__   ,#,             2022/06/17 15:00:08        */
/*   ##.............................##                                         */
/*    /##........................*##      Updated : Gabcollet                  */
/*       ###/................*###.                  2022/06/17 15:00:08        */
/*            ##############.                                                  */
/* *************************************************************************** */

#pragma once

#ifdef RUBBERDUCK_ENABLE_ASSERTS
 	#define RUBBERDUCK_ASSERT(x, ...) { if(!(x)) { RUBBERDUCK_ERROR("Assertion Failed: {0}", __VA_ARGS__); raise(SIGTRAP); } } 
 	#define RUBBERDUCK_CORE_ASSERT(x, ...) { if(!(x)) { RUBBERDUCK_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); raise(SIGTRAP); } } 
#else
 	#define RUBBERDUCK_ASSERT(x, ...)
 	#define RUBBERDUCK_CORE_ASSERT(x, ...)
#endif 

#define BIT(x) (1 << x)
