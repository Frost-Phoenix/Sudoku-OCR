#if !defined(CLI_H)
#define CLI_H

#include <stdio.h>
#include <sys/select.h>
#include <termios.h>
#include <unistd.h>


enum cli_color {
    CLI_BLACK,
    CLI_RED,
    CLI_GREEN,
    CLI_YELLOW,
    CLI_BLUE,
    CLI_MAGENTA,
    CLI_CYAN,
    CLI_WHITE,
};


#define cli_clear() printf("\033[H\033[J")
#define cli_reset() printf("\033[0m")

#define cli_goto(R, C) printf("\033[%d;%dH", R, C)

#define cli_set_fg(color)       printf("\033[3%dm", color)
#define cli_set_bg(color)       printf("\033[4%dm", color)
#define cli_set_fg_rgb(R, G, B) printf("\033[38;2;%d;%d;%dm", R, G, B)
#define cli_set_bg_rgb(R, G, B) printf("\033[48;2;%d;%d;%dm", R, G, B)

#define cli_bold()       printf("\033[1m")
#define cli_dimmed()     printf("\033[2m")
#define cli_italic()     printf("\033[3m")
#define cli_underlined() printf("\033[4m")


void cli_set_buffred_inputs(int enable);
int cli_kbhit();


#endif /* CLI_H */
