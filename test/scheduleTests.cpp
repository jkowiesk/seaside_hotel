#include <gtest/gtest.h>
#include <sstream>
#include "../src/schedule.h"
#include "../src/duty_entry.h"
#include <vector>

TEST(Schedule, addDuty) {
    Schedule schedule;
    DutyEntry duty {12, 11, "Cleaning"};
    schedule.addDuty("Monday", duty);
    std::vector<DutyEntry> monday = schedule.getDuties("Monday");
    EXPECT_EQ(monday[0], duty);
}

TEST(Schedule, print) {
    Schedule schedule;
    const char *msg =
            "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\
Monday)\n\
Tuesday)\n\
Wednesday)\n\
Thursday)\n\
Friday)\n\
Saturday)\n\
Sunday)\n\
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
    std::stringstream ss;
    ss << schedule;
    std::string msg_str = "";

    for (int i = 0; msg[i] != '\0'; i++) {
        msg_str += msg[i];
    }
    EXPECT_EQ(ss.str(), msg_str);
}