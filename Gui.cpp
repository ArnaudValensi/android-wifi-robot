#include <string>
#include "Gui.h"
#include "ui_Gui.h"
#include "Socketudp.h"
#include "Video.h"


Gui::Gui(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Gui)
{
  ui->setupUi(this);

  socketUDP = new CommunicationUDP("192.168.0.11", 6665);
  socketUDP->ouvrir();

  connect(ui->avancer, SIGNAL(pressed()), this, SLOT(avancer()));
  connect(ui->avancer, SIGNAL(released()), this, SLOT(avancerStop()));

  connect(ui->reculer, SIGNAL(pressed()), this, SLOT(reculer()));
  connect(ui->reculer, SIGNAL(released()), this, SLOT(reculerStop()));

  connect(ui->droite, SIGNAL(pressed()), this, SLOT(droite()));
  connect(ui->droite, SIGNAL(released()), this, SLOT(droiteStop()));

  connect(ui->gauche, SIGNAL(pressed()), this, SLOT(gauche()));
  connect(ui->gauche, SIGNAL(released()), this, SLOT(gaucheStop()));

  connect(ui->stop, SIGNAL(clicked()), this, SLOT(stop()));

}

Gui::~Gui()
{
  socketUDP->fermer();
  delete ui;
}

void Gui::init(char *str)
{
  video = new Video(ui->video->winId(), std::string(str));
  video->start();
}

void Gui::envoyerDatagramme(std::string data)
{
  socketUDP->envoyer(data);
}

void Gui::avancer()
{
  qDebug("avancer");
  envoyerDatagramme("a");
}

void Gui::avancerStop()
{
  qDebug("avancerStop");
  envoyerDatagramme("A");
}

void Gui::reculer()
{
  qDebug("reculer");
  envoyerDatagramme("r");
}

void Gui::reculerStop()
{
  qDebug("reculerStop");
  envoyerDatagramme("R");
}

void Gui::droite()
{
  qDebug("droite");
  envoyerDatagramme("d");
}

void Gui::droiteStop()
{
  qDebug("droiteStop");
  envoyerDatagramme("D");
}

void Gui::gauche()
{
  qDebug("gauche");
  envoyerDatagramme("g");
}

void Gui::gaucheStop()
{
  qDebug("gaucheStop");
  envoyerDatagramme("G");
}

void Gui::stop()
{
  qDebug("stop");
  envoyerDatagramme("s");
}
