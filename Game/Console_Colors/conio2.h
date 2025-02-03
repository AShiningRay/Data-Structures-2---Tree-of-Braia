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
    "\x1B[30m",  // BLACK
    "\x1B[34m",  // BLUE
    "\x1B[32m",  // GREEN
    "\x1B[36m",  // CYAN
    "\x1B[31m",  // RED
    "\x1B[35m",  // MAGENTA
    "\x1B[33m",  // BROWN
    "\x1B[37m",  // LIGHTGRAY
    "\x1B[90m",  // DARKGRAY
    "\x1B[94m",  // LIGHTBLUE
    "\x1B[92m",  // LIGHTGREEN
    "\x1B[96m",  // LIGHTCYAN
    "\x1B[91m",  // LIGHTRED
    "\x1B[95m",  // LIGHTMAGENTA
    "\x1B[93m",  // YELLOW
    "\x1B[97m"   // WHITE
};

const char* bgColorCodes[] = {
    "\x1B[40m",  // BLACK
    "\x1B[44m",  // BLUE
    "\x1B[42m",  // GREEN
    "\x1B[46m",  // CYAN
    "\x1B[41m",  // RED
    "\x1B[45m",  // MAGENTA
    "\x1B[43m",  // BROWN
    "\x1B[47m",  // LIGHTGRAY
    "\x1B[100m", // DARKGRAY
    "\x1B[104m", // LIGHTBLUE
    "\x1B[102m", // LIGHTGREEN
    "\x1B[106m", // LIGHTCYAN
    "\x1B[101m", // LIGHTRED
    "\x1B[105m", // LIGHTMAGENTA
    "\x1B[103m", // YELLOW
    "\x1B[107m"  // WHITE
};
#endif

void textbackground (int color);

void textcolor (int color);
