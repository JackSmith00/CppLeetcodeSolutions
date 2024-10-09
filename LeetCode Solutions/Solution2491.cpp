//
//  Solution2491.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 04/10/2024.
//
#include "solutions.h"

long long dividePlayersAttempt1(vector<int> &skill) {
    sort(skill.begin(), skill.end()); // sort players so highest skill can pair with lowest
    long long output = 0;
    for(int i = 0, j = (int) skill.size()-1, targetSkill = 0; i < j; i++, j--) { // two pointers converging to middle
        if(i == 0) { // case for first team, set target skill
            targetSkill = skill[i] + skill[j];
        } else if(skill[i] + skill[j] != targetSkill) { // if team doesn't match target skill, even teams cannot be made
            return -1;
        }
        output += skill[i] * skill[j]; // add chemistry to overall output
    }
    return output; // return output
}

long long Solution::dividePlayers(vector<int> &skill) {
    // completed after reading editorial
    int totalSkill = 0;
    unordered_map<int, int> skillCount;
    for(int s : skill) { // sum skills and count occurances of each skill
        totalSkill += s;
        skillCount[s] += 1;
    }
    
    if(totalSkill % (skill.size()/2) != 0) { // totalSkill can't be split evenly by teams
        return -1;
    }
    
    int target = totalSkill / (skill.size() / 2); // total skill divided by number of teams
    long long output = 0;
    
    for(auto& [currentSkill, currentSkillCount] : skillCount) { // loop found skills in map
        int partnerSkill = target - currentSkill; // skill required for matching partner
        
        if(skillCount.find(partnerSkill) == skillCount.end() || skillCount[partnerSkill] != currentSkillCount) {
            // partner not found, or imbalance between partners
            return -1;
        }
        
        // add chemistry to output for each pair found (ie the count with this skill pairing)
        output += currentSkillCount * currentSkill * partnerSkill;
    }
    
    return output / 2; // divide output by 2 as each team is counted twice (once for each player)
}
