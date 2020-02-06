int main(int argc, char** argv) {
    Args a(argc, argv);

    a.from

    size_t SZ = 1000;
    size_t ITER = a.iters;
    if (a.experiment == 1)
        boxed(SZ, ITER);
    if (a.experiment == -1)
        primitive(SZ,ITER);
    return 0;
}