#include <iostream>
#include <string>
#include <set>

using namespace std;

class Activity
{
    int start, end;
    int pos;
    char letter;

public:
    Activity(int start, int end, int pos)
    {
        this->pos = pos;
        this->start = start;
        this->end = end;
    }

    int getStart() const { return this->start; }
    int getEnd() const { return this->end; }
    int getPos() const { return this->pos; }

    bool operator<(const Activity &act) const
    {
        if (this->start < act.getStart())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N, Si, Ei;
        cin >> N;
        multiset<Activity> activities;

        for (int j = 0; j < N; j++)
        {
            cin >> Si >> Ei;
            activities.insert(Activity(Si, Ei, j));
        }

        string result(N, 'J');
        int jEnd = 0, cEnd = 0;
        multiset<Activity>::iterator it = activities.begin();
        for (; it != activities.end(); it++)
        {
            const Activity &act = *it;
            if (act.getStart() >= cEnd)
            {
                result[act.getPos()] = 'C';
                cEnd = act.getEnd();
                continue;
            }

            if (act.getStart() < jEnd)
            {
                result = "IMPOSSIBLE";
                break;
            }

            jEnd = act.getEnd();
        }

        cout << "Case #" << (i + 1) << ": " << result << endl;
    }

    return 0;
}