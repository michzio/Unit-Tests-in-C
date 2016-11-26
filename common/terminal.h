//
// Created by Michal Ziobro on 16/08/2016.
//

#ifndef UNIT_TESTS_TERMINAL_H
#define UNIT_TESTS_TERMINAL_H

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define TEST_FUNCTION_HEADER printf("\n=========== %s ==============\n", __func__)
#define SEPARATOR printf("====================================================\n")
#define TITLE_HEADER(title) printf("\n=========== %s ==============\n", title)

#endif //UNIT_TESTS_TERMINAL_H
