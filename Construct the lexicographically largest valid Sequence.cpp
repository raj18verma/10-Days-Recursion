vector<int> findValidSequence(vector<int> &answer, vector<int> &remaining, int index) {

    if (index == answer.size()) {
        return answer;
    }

    if (answer[index] != 0) {
        return findValidSequence(answer, remaining, index + 1);
    }

    for (int i = remaining.size() - 1; i > 0; i--) {
        if (remaining[i] == 0){
            continue;
        }
        if (i != 1 && index + i < answer.size() && answer[index + i] == 0) {
            answer[index] = i;
            answer[index + i] = i;
            remaining[i] = 0;
            vector<int> tempAnswer = findValidSequence(answer, remaining, index + 1);

            if (!tempAnswer.empty()){
                return tempAnswer;
            }
            remaining[i] = 1;
            answer[index] = 0;
            answer[index + i] = 0;
        }
        if (i == 1) {
            answer[index] = i;
            remaining[i] = 0;
            vector<int> tempAnswer = findValidSequence(answer, remaining, index + 1);

            if (!tempAnswer.empty()){
                return tempAnswer;
            }
            remaining[i] = 1;
            answer[index] = 0;
        }
    }
    return {};
}
vector<int> validSequence(int n) {

    vector<int> answer(2 * n - 1, 0);
    vector<int> remaining(n + 1, 1);
    return findValidSequence(answer, remaining, 0);
}
