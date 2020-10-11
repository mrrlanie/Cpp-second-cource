#include <vector>

class Set {
private:
    std::vector<int64_t> setVector;

public:
    Set() = default;

    explicit Set(const std::vector<int64_t> &set_vector) {
        for (auto i : set_vector) {
            Add(i);
        }
    }

    Set Union(const Set &anotherVec) const {
        Set unionSet(setVector);
        auto otherVector = anotherVec.setVector;
        for (auto i : otherVector) {
            if (!Contains(i)) {
                unionSet.Add(i);
            }
        }
        return unionSet;
    }

    Set Intersection(const Set &anotherVec) const {
        Set intersectionSet(setVector);
        auto vector = this->setVector;
        for (auto i : vector) {
            if (!anotherVec.Contains(i)) {
                intersectionSet.Remove(i);
            }
        }
        return intersectionSet;
    }

    Set Difference(const Set &anotherVec) const {
        Set differenceSet(setVector);
        auto otherVector = anotherVec.setVector;
        for (auto i : otherVector) {
            if (Contains(i)) {
                differenceSet.Remove(i);
            }
        }
        return differenceSet;
    }

    static Set SymmetricDifference(const Set &anotherVec) {
        const Set &unionSet(anotherVec);
        Set intersectionSet(anotherVec);
        return unionSet.Difference(intersectionSet);
    }

    // bc symmetric difference can be
    // interpret as "intersection" backwards


    void Add(int64_t value) {
        if (!Contains(value)) {
            setVector.push_back(value);
        }
    }

    void Remove(int64_t value) {
        if (Contains(value)) {
            setVector.erase(std::find(setVector.begin(),
                                      setVector.end(), value));
        }
    }

    bool Contains(int64_t value) const {
        auto isIn = std::find(setVector.begin(),
                              setVector.end(), value);
        if (isIn != setVector.end()) {
            return true;
        } else {
            return false;
        }
    }

    std::vector<int64_t> Data() const {
        return setVector;
    }
};