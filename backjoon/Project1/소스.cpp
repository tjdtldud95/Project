#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> list;
    int len = board.size();

    for (auto index : moves)
    {
        for (int i = 0; i < len; i++)
        {
            if (board[i][index - 1] != 0)
            {
                list.push_back(board[i][index - 1]);
                board[i][index - 1] = 0;
                break;
            }
        }
    }

    len = list.size();
    for (int i = 0; i < len - 1; i++)
    {
        if (list[i] == list[i + 1])
        {
            list.erase(list.begin() + i, list.begin() + i + 2);
            i = -1;
            len = list.size();
            answer += 2;
        }
    }

    return answer;
}