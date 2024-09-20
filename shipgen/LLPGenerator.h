#ifndef LLPGENERATOR_H
#define LLPGENERATOR_H 1

#include "TROOT.h"
#include "FairGenerator.h"
#include "TTree.h"                      // for TTree
#include "FairLogger.h"                 // for FairLogger, MESSAGE_ORIGIN

class FairPrimaryGenerator;

class LLPGenerator : public FairGenerator
{
 public:

  /** default constructor **/
  LLPGenerator();

  /** destructor **/
  virtual ~LLPGenerator();

  /** public method ReadEvent **/
  Bool_t ReadEvent(FairPrimaryGenerator*);
  virtual Bool_t Init(const char*, int); //!
  virtual Bool_t Init(const char*); //!
  Int_t GetNevents();

  void SetPositions(Double_t zTa=-5814.25, Double_t zDV=0.){
    ztarget      = zTa; // units cm (midpoint)
    zDecayVolume = zDV; // units cm (midpoint)
  }

 private:

 protected:
  Int_t parentid, n_2ry;
  Double_t px, py, pz, vx, vy, vz, energy, weight;
  Double_t px_2ry[500], py_2ry[500], pz_2ry[500], energy_2ry[500], pdg_2ry[500];
  TFile* fInputFile;
  TTree* fTree;
  FairLogger*  fLogger; //!   don't make it persistent, magic ROOT command
  int fNevents;
  int fn;
  ClassDef(LLPGenerator,1);
};

#endif /* !LLPGENERATOR_H */
