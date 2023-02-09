/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const hashTable = {};
    for (let i = 0; i < nums.length; i++) {
        if (hashTable[target - nums[i]] != undefined) {
            return [hashTable[target - nums[i]], i];
        }
        hashTable[nums[i]] = i;
    }
};