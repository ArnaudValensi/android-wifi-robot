#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <string>
#include "Socketudp.h"
#include "Video.h"


namespace Ui {
  class Gui;
}

class Gui : public QMainWindow
{
  Q_OBJECT

public:
  explicit Gui(QWidget *parent = 0);
  virtual ~Gui();
  void init(char *str);

private:
  Ui::Gui *ui;
  CommunicationUDP *socketUDP;
  Video *video;

  void envoyerDatagramme(std::string);

public slots:
  void avancer();
  void avancerStop();

  void reculer();
  void reculerStop();

  void droite();
  void droiteStop();

  void gauche();
  void gaucheStop();

  void stop();
};

#endif // GUI_H
