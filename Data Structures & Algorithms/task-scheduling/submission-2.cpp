
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        for (char task : tasks) {
            freq[task]++;
        }

        priority_queue<int> maxHeap;

        for (auto& entry : freq) {
            maxHeap.push(entry.second);
        }

        // {remaining frequency, available time}
        queue<pair<int, int>> cooldown;

        int time = 0;

        while (!maxHeap.empty() || !cooldown.empty()) {
            time++;

            // Execute the task with the highest remaining frequency
            if (!maxHeap.empty()) {
                int remaining = maxHeap.top() - 1;
                maxHeap.pop();

                if (remaining > 0) {
                    cooldown.push({remaining, time + n});
                }
            }

            // Return tasks whose cooldown has finished
            if (!cooldown.empty() && cooldown.front().second == time) {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};
