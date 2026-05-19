#include "musician_studio.h" 

Instrument::Instrument(string model_name, int sound_quality): model_name_(model_name){set_sound_quality(sound_quality);} 
void Instrument::set_sound_quality(int sound_quality){ (sound_quality >0 || sound_quality <= 100) ? sound_quality_=sound_quality : sound_quality_=10;} 
void Instrument::Play() const{ cout << "\nPlaying" << model_name_ << endl;} 

ostream& operator<<(ostream& out_ref, Instrument& i_ref) {
    out_ref << "\nModel: " << i_ref.model_name_ << endl << "Sound Quality: " << i_ref.sound_quality_ << endl; 
    return out_ref;} 
    
Musician::~Musician(){ cout << "\n<Musician>: destructor running for " << name_ << endl;} 

ostream& operator<<(ostream& out_ref, Musician& m_ref) { 
    if(m_ref.instr_ptr_.empty()){ 
        out_ref << "\nThe musician's name is " << m_ref.name_ << endl << "He cannot play any instruments yet." << endl;
        
    }else{ 
        out_ref << "\nThe musician's name is " << m_ref.name_ << endl << "He can play the following:"<< endl; 
        for(int i=0; i< m_ref.instr_ptr_.size(); i++){ out_ref << left  << "Instrument: " << setw(15)<< m_ref.instr_ptr_[i]>name()  << "Years of experience: "  << m_ref.years_of_experience_[i] << endl;}}     
    return out_ref;} 
    
void Musician::AddInstrument(const Instrument* instr_ptr, int years_of_experience){ 
    if (instr_ptr != nullptr){ 
        instr_ptr_.push_back(instr_ptr); 
        years_of_experience_.push_back(years_of_experience); 
    }else{ 
        cerr << "<Instrument>: nullptr encountered!"; 
        exit(1);}
}