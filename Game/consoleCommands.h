void clearConsoleScreen() 
{
#ifdef __linux__
            system("clear");
#elif _WIN32
            system("cls");
#endif
}

void moveCursorRightBy(int numChars) { printf("\x1B[%dC", numChars); }
void moveCursorDownBy(int numChars) { printf("\x1B[%dB", numChars); }
void moveCursorUpBy(int numChars) { printf("\x1B[%dA", numChars); }
void moveCursorLeftBy(int numChars) { printf("\x1B[%dD", numChars); }
void useBoldConsoleText() { printf("\x1B[1m"); }
void useFaintConsoleText() { printf("\x1B[2m"); }
void useItalicConsoleText() { printf("\x1B[3m"); }
void useUnderlineConsoleText() { printf("\x1B[4m"); }
void useInverseConsoleText() { printf("\x1B[7m"); }
void useStrikeThroughConsoleText() { printf("\x1B[9m"); }
void restoreConsoleText() { printf("\x1B[0m"); }
