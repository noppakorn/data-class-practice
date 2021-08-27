#include <vector>
using std::pair;
using std::vector;

namespace CP {
template <typename KeyT, typename MappedT>
class unordered_map {
    typedef pair<KeyT, MappedT> ValueT;
    typedef vector<ValueT> BucketT;

};
}
