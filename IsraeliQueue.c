#include "IsraeliQueue.h"

typedef struct IsraeliQueue_t{
    FriendshipFunction *friendship_functions;
    ComparisonFunction comparison_function;
    int friendship_threshold;
    int rivalry_threshold;
}
 *IsraeliQueue;
