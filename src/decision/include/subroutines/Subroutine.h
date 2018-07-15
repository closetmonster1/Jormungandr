/*
 * Created By: Reid Oliveira
 * Created On: March 17, 2018
 * Description: Abstract class for subroutines
 */

#ifndef DECISION_SUBROUTINE_H
#define DECISION_SUBROUTINE_H

#include <geometry_msgs/Twist.h>
#include <ros/ros.h>

/**
 * pre defined directions for subroutines to use
 * example: z_rotation = RIGHT
 */
static const double RIGHT    = -0.25;
static const double LEFT     = 0.25;
static const double FORWARD  = 0.25;
static const double BACKWARD = -0.25;
static const double UP       = 0.25;
static const double DOWN     = -0.25;

class Subroutine {
  private:
    // hold onto these, automatically unsubscribe/unadvertise when out of scope
    ros::Publisher publisher_;
    std::vector<ros::Subscriber> subscriptions_;

  public:
    Subroutine();
    virtual std::string getName() = 0;

    void startup();
    void shutdown();

  protected:
    /**
     * Publishes a Twist message containing the movement decision
     * @param msg
     */
    void publishCommand(const geometry_msgs::Twist& msg);

    /**
     * Utility function for creating a geometry_msgs::Vector3
     * @param x
     * @param y
     * @param z
     * @return x, y and z in order in a Vector3
     */
    geometry_msgs::Vector3 makeVector(double x, double y, double z);

    /**
     * Gets the subscriptions for the subroutine. Each implementing class of
     * subroutine is responsible for having this function return all subscriber
     * objects it needs to work.
     * @param nh node handle used to create the subscribers
     * @return a vector of all subscriptions the subroutine needs
     */
    virtual std::vector<ros::Subscriber>
    getSubscriptions(ros::NodeHandle nh) = 0;
};

#endif // DECISION_SUBROUTINE_H
