#pragma
#include <string>
using namespace std;

class person_t { // immutable
public:
    enum gender_t{ female, male };

    person_t():m_name("jack"),m_surname("bauer"),m_gender(male),m_age(56) {}

    person_t(const string &mName, const string &mSurname, gender_t mGender, int mAge) : m_name(mName),
                                                                                        m_surname(mSurname),
                                                                                        m_gender(mGender),
                                                                                        m_age(mAge) {}

    const string name() const {
        return m_name;
    }

    const string surname() const {
        return m_surname;
    }

    gender_t gender() const {
        return m_gender;
    }

    int age() const {
        return m_age;
    }

private:
    string m_name;
    string m_surname;
    gender_t m_gender;
    int m_age;
};
