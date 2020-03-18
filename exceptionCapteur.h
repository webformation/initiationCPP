#ifndef EXCEPTIONCAPTEUR_H_INCLUDED
#define EXCEPTIONCAPTEUR_H_INCLUDED


class exceptionCapteur {
private:
    string message;
public:
    exceptionCapteur(string message) :  message(message) {}
    string what() {
        return message;
    }
};

class capteurParametreInvalide : public exceptionCapteur {
public:
    using exceptionCapteur::exceptionCapteur;
};

class capteurErreurInitialisation : public exceptionCapteur {
public:
    using exceptionCapteur::exceptionCapteur;
};

class capteurErreurLecture : public exceptionCapteur {
public:
    using exceptionCapteur::exceptionCapteur;
};
#endif // EXCEPTIONCAPTEUR_H_INCLUDED
