class Args : public Object {
public:
    char* file = nullptr;

    Args(int argc, char** argv) {
        for (size_t ii = 1; ii < argc; ii++) {
            char* a = argv[ii];
            assert(++i < argc);
            char* n = argv[i];
            if (strcmp(a,"-i") == 0) {

            } else if (strcmp(a,"-from") == 0) {

            }
        }
    }

}