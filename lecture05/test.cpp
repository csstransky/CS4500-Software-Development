# define ASERT_TRUE(A) \
    ASSERT_EQ((a), true);
# define ASSERT_EXIT_ZERO(a) \
    ASSERT_EXIT(a(), ::testing::ExitedWideCode(0), ".*");


void test1() {
    ASSERT_TRUE(1 != 0);
    exit(0);
}

TEST(A1, test1) { ASSERT_EXIT_ZERO(test1) }

void test2()

