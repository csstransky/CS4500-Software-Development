

class Args : public Object {
public:
    char* filename;

    Args(int argc, char** argv) {
        // filename = argv[i];
    }
}

int main(int getc, char** argv) {
    Args a(argc, argv);
    // some way to print
    a.filename;
    Adapter sor(a);
    sor.strip(a);
    Schema scm;
    sor.infer_schema(scm);
    ???
    ???
}