class Solution {
public:
    string justify(vector<string>& words, int first_string, int final_string, int char_count, int max, bool last_line) {
        string solution;
        solution.reserve(max);
        int num_strings = final_string - first_string;
        // Find number of spaces between words
        int spaces = (num_strings == 1) ? max - char_count : (last_line) ? 1 : (max - char_count) / (num_strings - 1);
        int extra_padding = (num_strings == 1 || last_line) ? 0 : max - char_count - (num_strings - 1) * spaces;

        for (int i = first_string; i < final_string - 1; ++i) {
            string space(spaces + ((extra_padding) ? 1 : 0), ' ');
            if (extra_padding) {
                --extra_padding;
            }
            solution.append(words[i]).append(space);
        }
        solution.append(words[final_string - 1]);
        if (num_strings == 1) {
            solution.append(string(spaces, ' '));
        } else if (last_line && (max - (num_strings - 1 + char_count)) > 0) {
            solution.append(string(max - (num_strings - 1 + char_count), ' '));
        }
        return solution;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> solution;
        int first_string = 0;
        int char_count = 0;
        int space_count = 0;
        for (int i = 0; i < words.size(); ++i) {
            if (char_count + words[i].size() + space_count <= maxWidth) {
                char_count += words[i].size();
                ++space_count;
            } else {
                solution.push_back(justify(words, first_string, i, char_count, maxWidth, false));
                char_count = words[i].size();
                first_string = i;
                space_count = 1;
            }
        }
        solution.push_back(justify(words, first_string, words.size(), char_count, maxWidth, true));
        return solution;
    }
};