typedef enum
{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
} SCREENCOLORS;

#ifdef __linux__
const char* colorCodes[] = {
    "\033[30m",  // BLACK
    "\033[34m",  // BLUE
    "\033[32m",  // GREEN
    "\033[36m",  // CYAN
    "\033[31m",  // RED
    "\033[35m",  // MAGENTA
    "\033[33m",  // BROWN
    "\033[37m",  // LIGHTGRAY
    "\033[90m",  // DARKGRAY
    "\033[94m",  // LIGHTBLUE
    "\033[92m",  // LIGHTGREEN
    "\033[96m",  // LIGHTCYAN
    "\033[91m",  // LIGHTRED
    "\033[95m",  // LIGHTMAGENTA
    "\033[93m",  // YELLOW
    "\033[97m"   // WHITE
};

const char* bgColorCodes[] = {
    "\033[40m",  // BLACK
    "\033[44m",  // BLUE
    "\033[42m",  // GREEN
    "\033[46m",  // CYAN
    "\033[41m",  // RED
    "\033[45m",  // MAGENTA
    "\033[43m",  // BROWN
    "\033[47m",  // LIGHTGRAY
    "\033[100m", // DARKGRAY
    "\033[104m", // LIGHTBLUE
    "\033[102m", // LIGHTGREEN
    "\033[106m", // LIGHTCYAN
    "\033[101m", // LIGHTRED
    "\033[105m", // LIGHTMAGENTA
    "\033[103m", // YELLOW
    "\033[107m"  // WHITE
};
#endif

void textbackground (int color);

void textcolor (int color);
