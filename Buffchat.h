#ifndef BUFFCHAT_H
#define BUFFCHAT_H
#include <iostream>
#include "Post.cpp"
#include "User.cpp"

using  namespace std;

class Buffchat 
{
    private:
        static const int posts_size_ = 50;
        static const int users_size_ = 50;    
        Post posts[posts_size_];
        User users[users_size_];
        int num_posts_;
        int num_users_;

    public:
    Buffchat();
    int getPostSize();
    int getUserSize();
    int getNumPosts();
    int getNumUsers();
    int readPosts(string file_name);
    void printPostsByYear(string year);
    int readLikes(string file_name);
    int getLikes(string post_author, string username);
    void findTagUser(string username_tag);
    bool addPost(string post_body, string post_author, string date);
    void printPopularPosts(int count, string year);
    Buffchat findLeastActiveUser();
    int countUniqueLikes(string post_author);
};
#endif



    
