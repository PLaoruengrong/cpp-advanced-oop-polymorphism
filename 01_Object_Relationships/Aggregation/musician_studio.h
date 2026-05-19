#ifndef MUSICIAN_STUDIO_H_ 
#define MUSICIAN_STUDIO_H_ 
#include <iostream> 
#include <string> 
#include <vector> 
#include <iomanip> 
using namespace std; 

class Musician; 

class Instrument{ 
    friend ostream& operator << (ostream& out_ref, Instrument& i_ref); 
    private: 
        string model_name_; 
        int sound_quality_; 
    public: 
        Instrument(string model_name = " ", int sound_quality = 10); 
        string name() const {return model_name_;}; 
        void set_sound_quality(int sound_quality); 
        void Play() const;}; 
        
class Musician{ 
    friend ostream& operator << (ostream& out_ref, Musician& m_ref); 
    private: 
        string name_; 
        vector<int> years_of_experience_; 
        vector<const Instrument*> instr_ptr_; 
    public: 
        Musician(string name): name_(name){}; 
        ~Musician(); 
        const Instrument* AccessInstrument(int idx) const {return instr_ptr_[idx];}; 
        void AddInstrument(const Instrument* instr_ptr, int years_of_experience);}; 

#endif