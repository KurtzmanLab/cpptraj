#ifndef INC_FRAMELIST_H
#define INC_FRAMELIST_H
#include "TopologyList.h"
#include "ReferenceFrame.h"
// Class: FrameList
/// Hold a series of Frame classes which have been read in from trajectories. 
class FrameList {
  public:
    FrameList();
    ~FrameList();
    void Clear();
    void SetDebug(int);
    /// Return the current active reference frame
    Frame* ActiveReference();
    /// Set the active reference frame
    int SetActiveRef(int);
    /// Add a reference frame based on given args
    int AddRefFrame(ArgList&, TopologyList const&);
    /// Get reference frame based on given args
    ReferenceFrame GetFrameFromArgs(ArgList&) const;
    /// Get reference frame with given name.
    ReferenceFrame GetFrameByName(std::string const&) const;
    /// Print all reference frames.
    void List() const;
    /// \return the number of reference frames.
    int NumFrames() const { return (int)frames_.size(); }
  private:
    std::vector<ReferenceFrame> frames_;
    int activeRefNum_;
    int debug_;
};
#endif
