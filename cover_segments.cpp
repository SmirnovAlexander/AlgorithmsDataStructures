#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

typedef std::pair<int, int> Segment;

/**
 * Driver function to sort the vector elements
 * by second element of pairs
 */
bool sortbysec(const std::pair<int, int> a, const std::pair<int, int> b) {
    return (a.second < b.second);
}

/**
 * Cover segments with dots.
 *
 * Given segments find least cardinality set
 * of dots that every segment contains
 * at least 1 dot.
 *
 * @param segments Vector contains pairs
 *     of integers defining segment.
 * @return Dots which cover segments.
 */
std::vector<int> get_covering_set(std::vector<Segment> segments) {
    std::vector<int> result;

    // Sorting segments.
    std::sort(segments.begin(), segments.end(), sortbysec);

    // Assume that adding most right node
    // of 1st segment will not ruin
    // optimum solution.
    result.push_back(segments[0].second);

    // Adding right dot of current segment
    // to result vector if segment does not
    // contain last dot in result vector.
    for (std::size_t i = 1; i < segments.size(); i++) {
        if (result.back() < segments[i].first)
            result.push_back(segments[i].second);
    }

    return result;
}

int main(void) {
    int segments_count;
    std::cin >> segments_count;
    std::vector<Segment> segments(segments_count);
    for (int i = 0; i < segments_count; i++) {
        std::cin >> segments[i].first >> segments[i].second;
    }

    std::vector<int> points = get_covering_set(segments);
    std::cout << points.size() << std::endl;
    for (std::size_t i = 0; i < points.size(); i++) {
        std::cout << points[i] << " ";
    }
    std::cout << std::endl;
}
