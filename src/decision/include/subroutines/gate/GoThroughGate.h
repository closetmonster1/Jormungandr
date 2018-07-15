/*
 * Created By: Reid Oliveira
 * Created On: May 19, 2018
 * Description: Subroutine that simply proceeds forward through the gate
 */

#ifndef DECISION_GOTHROUGHGATE_H
#define DECISION_GOTHROUGHGATE_H

#include "Subroutine.h"
#include <gate_detect/gateDetectMsg.h>

/*
 * Subroutine: GoThroughGate
 *
 * Function: proceeds forward through the gate
 *
 */
class GoThroughGate : public Subroutine {
  public:
    GoThroughGate() : Subroutine() {}
    std::string getName() override { return "GoThroughGate"; }

    std::vector<ros::Subscriber> getSubscriptions(ros::NodeHandle nh) override;

  private:
    void decisionCallback(const gate_detect::gateDetectMsg::ConstPtr& msg);
};

#endif // DECISION_GOTHROUGHGATE_H
