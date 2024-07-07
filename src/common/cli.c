#include "../include/common/cli.h"


void cli_set_buffred_inputs(int enable) {
    static int enabled = 1;
    static struct termios old;
    struct termios new;

    if (enable && !enabled) {
        /* restore the former settings */
        tcsetattr(STDIN_FILENO, TCSANOW, &old);
        /* make cursor visible, reset all modes */
        printf("\033[?25h\033[m");
        enabled = 1;
    } else if (!enable && enabled) {
        /* get the terminal settings for standard input */
        tcgetattr(STDIN_FILENO, &new);
        /* make cursor invisible, clear screen */
        printf("\033[?25l\033[2J");
        /* keep old setting to restore them at the end */
        old = new;
        /* disable canonical mode (buffeRED_CLI i/o) and local echo */
        new.c_lflag &= (~ICANON & ~ECHO);
        /* set the new settings immediately */
        tcsetattr(STDIN_FILENO, TCSANOW, &new);
        enabled = 0;
    }
}

int cli_kbhit() {
    struct timeval timeout;
    fd_set rdset;

    FD_ZERO(&rdset);
    FD_SET(STDIN_FILENO, &rdset);
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;

    return select(STDIN_FILENO + 1, &rdset, NULL, NULL, &timeout) > 0;
}
