template <typename T>
struct myComparator
{
    bool operator() (T a, T b) const
    {
        return a < b;
    }
};