#include "Post.h"
#

using namespace std;

int main()
{
    Post my_post_1 = Post(); // default constructor
    cout << "Post author " << my_post_1.getPostAuthor() << endl;
    cout << "Post body " << my_post_1.getPostBody() << endl;
    cout << "Post date " << my_post_1.getPostDate() << endl;
    cout << "Post likes " << my_post_1.getPostLikes() << endl;

    Post my_post_2 = Post("new post","Raegan", 10, "10/02/22"); // parameterized constructor
    cout << "Post author " << my_post_2.getPostAuthor() << endl;
    cout << "Post body " << my_post_2.getPostBody() << endl;
    cout << "Post date " << my_post_2.getPostDate() << endl;
    cout << "Post likes " << my_post_2.getPostLikes() << endl;

    return 0;
}
