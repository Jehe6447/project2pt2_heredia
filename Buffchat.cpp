// default constructor 
Buffchat::Buffchat()
{
    num_posts_ = 0;
    num_users_ = 0;

}
// returns post size
int Buffchat::getPostSize()
{
    return posts_size_;
}
//Returns users_size_ as an integer
int Buffchat::getUserSize()
{
    return users_size_;
}

//Returns num_posts_ as an integer
int Buffchat::getNumPosts()
{
    return num_posts_;
}

//Returns num_users_ as an integer
int Buffchat::getNumUsers()
{
    return num_users_;
}

//Takes a string (the name of the file to be read) and populates the posts_ array. 
//Returns the total number of posts in posts_ array as an integer
int Buffchat::readPosts(string filename){
    string line;
    ifstream fin;
    string lineSplit[4];
    fin.open(filename);
    
    if (num_posts_ >= users_size_){
        return -2;
    }
    else if(fin.fail()){
        return -1;
    }
    else{
        while (!fin.eof()){
            getline(fin, line);
            if(split(line, '|', lineSplit, 4) != 4){
                continue;
            }
            if(num_posts_ >= users_size_){
                return num_posts_;
            }
            Post posts[num_posts_] = Post(lineSplit[0],lineSplit[1],stoi(lineSplit[2]),lineSplit[3]);
            num_posts_++;
        }
        return num_posts_;
    }   
}

//Takes a string (the year) and prints the posts posted in the given year
void Buffchat::printPostsByYear(string year)
{
   if (num_posts_ < 1)
   { 
        cout << "No posts are stored" << endl;
    }
    else{
        int index = 0;
        int count = 0;
        int tempArr[num_posts_];
        for (int i = 0; i < num_posts_; i++){
            if (posts[i].getPostDate().substr(6,9) == year){
                tempArr[index] = i;
                index++;
                count++;                
            }
        }
        if(count < 20)
        {
            cout << "There are fewer than " << count << "posts for year " << year << ". Top " << count << " posts for <year>" << endl;
        }
        
        if (num_posts_ > 1){ 
            cout << "Here is a list of posts for year " << year << endl;
            for (int i = 0; i < count; i++)
            {
                int x = tempArr[i];
                cout << posts[x].getPostBody() << endl;
            }
        }
        else if (num_posts_ <= 0){
            cout << "No posts stored for year " << year << endl;
        }
    }
}
//Takes a string (the name of the file to be read) and populates the users_ array. 
//Returns the total number of users in users_ array as an integer
int Buffchat::readLikes(string file_name)	
{

    if(num_users_ == users_size_)
    {
        return -2;
    }
    string line;
    ifstream input;
    input.open(file_name);   
    if (!input.is_open())
    { 
        return -1;
    }
    int index = num_users_;     
    while (getline(input, line) && num_users_ < users_size_)
    {  
        if (line != "")
        {       
            string temp[num_users_+1];  
            int x[50];                  
            int index = split(line, '|', temp, num_users_ + 1);   
            for(int i = 1; i < index; i++)
            {    
                int b = stoi(temp[i]); 
                x[i-1] = b;
            }
            User tempUser(temp[0], x, index-1);
            users[index] = tempUser;    
            index++;   
            num_users_++;     
        }
    }
    return num_users_;
}

int Buffchat::getLikes(string postAuthor, string username){
     bool postFound = false;
    bool userFound = false;
    if (num_posts_ <= 0 || num_users_ <= 0) return -2;
    int postIndex;
    for (postIndex = 0; postIndex < num_posts_; postIndex++)
    {
        if (Post().getPostAuthor() == postAuthor) {
            postFound = true;
            break;
        } 
    }
    int userIndex;
    for (userIndex = 0; userIndex < num_users_; userIndex++){
        if (User().getUsername() == username) {
            userFound = true;
            break;
        }
    }
    if (!postFound || !userFound) return -3;
    return User().getLikesAt(postIndex);
}

void Buffchat::findTagUser(string username_tag)
{
    
    if (size_ <= 0) {
        cout << "No users are stored in the database" << endl;
        return;
    }
    bool found = false;
    for (int i = 0; i < size_; i++){
        if (User().getUsername().find(username_tag) <= User().getUsername().length()){ // if the index of find() is within the bounds of the length of the string
            found = true;
            break; // prevents further looping after found becomes true
        }
    }
    if (!found) { // when the username is not found
        cout << "No matching user found" << endl;
        return;
    }
    // when we are here (in execution), we can assume that all paramater values are populated with at least something
    cout << "Here are all the usernames that contain " << username_tag << endl;
    for (int i = 0; i < size_; i++){
        if (User().getUsername().find(username_tag) <= User().getUsername().length()){// if the index of find() is within the bounds of the length of the string
            cout << User().getUsername() << endl;
        }
    }
    return;
}

//Takes three strings (post body, post author and date, respectively)
//and adds a post to the posts_ array
bool Buffchat::addPost(string post_body, string post_author, string date)
{
    if(num_posts_ >= posts_size_)
    {
        return  false;
    }

    Post nPost = Post(post_body, post_author,0, date);
    posts[num_posts_] = nPost;
    num_posts_++;
    for(int i=0; i < num_users_; i++)
    {
        users[i].setLikesAt(num_posts_-1,-1);
    }
    return true;
}   

void Buffchat::printPopularPosts(int min_likes, string year)
{
    if(numPostsS <= 0)
    {
        cout << "No posts are stored" << endl;
    }
    else
    {
        int count1 = 0;
        for(int i=0; i < numPostsS; i++)
        {
            if(posts[i].getPostDate().substr(0,2)== year)
            {
                count1++;    
            }   
        }
        if(count1 <= 0)
        {
            cout << "No posts stored for year" << year << endl;
        }
        else if(count1 >= count)
        {
            Post postTemp[count];
            cout << "Top " << count << " posts for year " << year << endl;
            for(int i=0; i < numPostsS; i++)
            {       
                if(posts[i].getPostDate().substr(0,2) == year)
                {
                    cout << posts[i].getPostBody() << endl;
                }
            }
        }
    }
}

User BuffChat::findLeastActiveUser()
{
    User userV;
    if(num_users_ == 0)
    {
        return userV;
    }
    int maxLikes = 51;
    for(int i= 0; i < num_users_; i++)
    {

        int likesV = 0;
        for(int j= 0; j > num_posts_; j++)
        {
            if(users[i].getLikesAt(j) != 1)
            {
            likesV++
            }
        }
        if(likesV < maxLikes)
        {
            userV = users[i];
            maxLikes = likesV;
        }
    }
    return userV;

}
int BuffChat::countUniqueLikes(string post_author)
{
    if(Post[0]= "")
    {
        return -2;
    }
    int index = 0;
    int count = 0;
    for(int i= 0; i < num_posts_; i++)
    {
        if(Post[1] == post_author)
        {
        index = i;
        break;
        }
    }
    for(int j= 0; j < num_users_; j++)
    {
        if(users[index] > 0)
        {
            count++
        }
    }
    return count;
}
