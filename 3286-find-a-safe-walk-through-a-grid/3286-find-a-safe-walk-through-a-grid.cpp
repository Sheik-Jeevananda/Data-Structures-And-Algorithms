class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n = grid.size();
        int m = grid[0].size();

        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;

        queue<pair<int, pair<int, int>>> q;
        q.push({startHealth, {0, 0}});

        vector<vector<int>> best(n, vector<int>(m, -1));
        best[0][0] = startHealth;

        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, -1, 0, 1};

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int energy = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == n - 1 && c == m - 1)
                return true;

            for (int k = 0; k < 4; k++) {

                int nr = r + delr[k];
                int nc = c + delc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {

                    int newEnergy = energy - grid[nr][nc];

                    if (newEnergy > 0 && newEnergy > best[nr][nc]) {
                        best[nr][nc] = newEnergy;
                        q.push({newEnergy, {nr, nc}});
                    }
                }
            }
        }

        return false;
    }
};