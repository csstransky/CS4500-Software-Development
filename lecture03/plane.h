
/**
 * Plane: this class represents an airplane with
 *        minimal flying capacities, it has a pilot 
 *        and a way to land.     
 * author: stransky.c@husky.neu.edu
 */
class Plane {
public:
    String pilot; // name of the captain

    /**
     * Lands the plane. Subclass responsibility.
     * @arg fast    should we use emergency landing
     */
    virtual void land(bool fast) { assert(false); }
};