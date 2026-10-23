#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    // TODO: Implement round_down_scores.
    std::vector<int> scores_int;
    int i=0;
    while(i<student_scores.size()){
        scores_int.push_back(static_cast<int>(student_scores[i]));
        i++;
    }
    return scores_int;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    // TODO: Implement count_failed_students

    //init
    int failed_students = 0;
    int i = 0;

    //creating while loop parameters
    int size_of_class = student_scores.size();
    while(i<size_of_class){
        if (student_scores[i] <= 40) failed_students++;
        i++;
    }
    return failed_students;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    // TODO: Implement letter_grades
    int B = 86;
    int C = 71;
    int D = 56;
    int F = 41;
    
    if (highest_score < 100){
        int interval = static_cast<int>((highest_score-40)/4);
        B = highest_score - interval;
        C = B - interval;
        D = C - interval;
        F = D - interval;
    }
    std::array<int, 4> curve = {F,D,C,B};
    return curve;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    // TODO: Implement student_ranking

    std::vector<std::string> name_score;
    std::string name_score_string = "";
    int size_of_class = student_names.size();
    int i = 0;
    while(i < size_of_class){
        name_score_string = std::to_string(i+1)      +
                            ". "                     +
                            student_names[i]         +
                            ": "                     +
                            std::to_string(student_scores[i]);
        name_score.push_back(name_score_string);
        i++;
    }
    return name_score;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    // TODO: Implement perfect_score
    
    int i = 0;
    while(i < student_scores.size()){
        if (student_scores[i] == 100) return student_names[i];
        i++;
    }
    return "";
}
