
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char task : tasks) freq[task]++;

        priority_queue<int> maxHeap;
        for (auto& entry : freq) {
            maxHeap.push(entry.second);
        }

        // {remaining frequency, available time}
        queue<pair<int, int>> cooldown;
        int time = 0;

        while (!maxHeap.empty() || !cooldown.empty()) {
            time++;

            // Release tasks whose cooldown has finished
            if (!cooldown.empty() && cooldown.front().second <= time) {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }

            if (!maxHeap.empty()) {
                int remaining = maxHeap.top() - 1;
                maxHeap.pop();

                if (remaining > 0) {
                    cooldown.push({remaining, time + n + 1});
                }
            }
        }

        return time;
    }
};
