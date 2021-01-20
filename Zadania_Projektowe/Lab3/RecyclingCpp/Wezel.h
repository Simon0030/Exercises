#include <memory>


using namespace std;


class Wezel{
    private:;
    public:

        ~Wezel();
        shared_ptr<Wezel> next;

    };