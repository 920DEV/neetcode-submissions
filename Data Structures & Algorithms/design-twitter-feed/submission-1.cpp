class Twitter {
public:
    unordered_map<int, unordered_set<int>> usersMap;

    vector<pair<int, int>> userNews;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        userNews.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ansNewsFeed;
        int n = userNews.size();

        int i = n - 1;
        int j = 0;

        auto it = usersMap.find(userId);
     while (i >= 0 && j < 10) { 
    int authorId = userNews[i].first;

    if (authorId == userId ||
        (it != usersMap.end() && /// using this now the lookip tc will be O(1 ) -> map & O(1 ) set 
         it->second.find(authorId) != it->second.end())) {

        ansNewsFeed.push_back(userNews[i].second);
        j++;
    }

    i--;
}
        return ansNewsFeed;
    }

    void follow(int followerId, int followeeId) {
        usersMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        usersMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */