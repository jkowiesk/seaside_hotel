#include <gtest/gtest.h>
#include "../src/duty_entry.h"

TEST(DutyEntry, constructor) {
    DutyEntry dutyEntry(18, 0, "Cleaning room");
    EXPECT_EQ(dutyEntry.getHour(), 18);

}