class Solution {
public:
    long long minTime(std::vector<int>& skill, std::vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        std::vector<long long> done(n + 1, 0);
        std::vector<long long> skillLL(n);
        for (int i = 0; i < n; ++i) skillLL[i] = static_cast<long long>(skill[i]);

        for (int j = 0; j < m; ++j) {
            long long mj = static_cast<long long>(mana[j]);

            long long prev = 0;
            for (int i = 0; i < n; ++i) {
                long long add = mj * skillLL[i];
                prev = std::max(done[i + 1], done[i]) + add;
                done[i + 1] = prev;
            }

            for (int i = n - 1; i > 0; --i)
                done[i] = done[i + 1] - mj * skillLL[i];
        }

        return done[n];
    }
};
