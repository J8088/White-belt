#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct  Specialization
{
    string spec;
    explicit Specialization(string s)
    {
        spec = s;
    }
};

struct Course
{
    string cr;
     explicit Course(string s) {
        cr = s;
    }
};

struct Week
{
    string wk;
    explicit Week(string s) {
        wk = s;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(Specialization sp, Course c, Week w)
    {
        specialization = sp.spec;
        course = c.cr;
        week = w.wk;
    }
};

