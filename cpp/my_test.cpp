#include "recyclingstation.h"
#include "garbage.h"
#include "crusher.h"

#include <gmock/gmock.h>

class MyTest : public ::testing::Test {
};


TEST_F(MyTest, test_recycle)
{
    auto sm = Smelter();
    auto cr = Crusher();
    auto m1 = ScrapMetal(10);
    auto g2 = Glass(3);

    std::vector<Garbage *> load = {&g2, &m1};
    recycle(load, sm, cr);

    EXPECT_EQ (0, 0);

}

