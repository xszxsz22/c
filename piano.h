#ifndef PIANO_H
#define PIANO_H

#include <QMainWindow>
#include "ui_piano.h"
#include <QSound>
#include <QSoundEffect>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QList>
#include <QPair>
#include <QTime>
#include <QTimer>
namespace Ui {
class piano;
}

class Piano : public QMainWindow
{
    Q_OBJECT

public:
    explicit Piano(QWidget *parent = 0);
    ~Piano();

private slots:
    void on_A2_clicked();

    void on_A2s_clicked();

    void on_B2_clicked();

    void on_c5_clicked();

    void on_voicehigh_valueChanged(int arg1);

    void on_c1_clicked();

    void on_c1s_clicked();

    void on_d1_clicked();

    void on_d1s_clicked();

    void on_e1_clicked();

    void on_f1_clicked();

    void on_f1s_clicked();

    void on_g1_clicked();

    void on_g1s_clicked();

    void on_a1_clicked();

    void on_a1s_clicked();

    void on_b1_clicked();


    void on_playButton_clicked();

    void on_recordButton_clicked();

    void on_deleteButton_clicked();
    void startPlayback();
    void stopPlayback();
    void playNextRecordedKey();
    void updateKeys(int value); // Slot to update keys

private:
    Ui::piano *ui;
    QSoundEffect *soundEffectA2;
    QSoundEffect *soundEffectA2s;
    QSoundEffect *soundEffectB2;
    QSoundEffect *soundEffectc5;
    QSoundEffect *soundEffectC1;
    QSoundEffect *soundEffectC1s;
    QSoundEffect *soundEffectD1;
    QSoundEffect *soundEffectD1s;
    QSoundEffect *soundEffectE1;
    QSoundEffect *soundEffectF1;
    QSoundEffect *soundEffectF1s;
    QSoundEffect *soundEffectG1;
    QSoundEffect *soundEffectG1s;
    QSoundEffect *soundEffectA1;
    QSoundEffect *soundEffectA1s;
    QSoundEffect *soundEffectB1;
    QSoundEffect *soundEffectC;
    QSoundEffect *soundEffectCs;
    QSoundEffect *soundEffectD;
    QSoundEffect *soundEffectDs;
    QSoundEffect *soundEffectE;
    QSoundEffect *soundEffectF;
    QSoundEffect *soundEffectFs;
    QSoundEffect *soundEffectG;
    QSoundEffect *soundEffectGs;
    QSoundEffect *soundEffectA;
    QSoundEffect *soundEffectAs;
    QSoundEffect *soundEffectB;
    QSoundEffect *soundEffectc;
    QSoundEffect *soundEffectcs;
    QSoundEffect *soundEffectd;
    QSoundEffect *soundEffectds;
    QSoundEffect *soundEffecte;
    QSoundEffect *soundEffectf;
    QSoundEffect *soundEffectfs;
    QSoundEffect *soundEffectg;
    QSoundEffect *soundEffectgs;
    QSoundEffect *soundEffecta;
    QSoundEffect *soundEffectas;
    QSoundEffect *soundEffectb;
    QSoundEffect *soundEffectc1;
    QSoundEffect *soundEffectc1s;
    QSoundEffect *soundEffectd1;
    QSoundEffect *soundEffectd1s;
    QSoundEffect *soundEffecte1;
    QSoundEffect *soundEffectf1;
    QSoundEffect *soundEffectf1s;
    QSoundEffect *soundEffectg1;
    QSoundEffect *soundEffectg1s;
    QSoundEffect *soundEffecta1;
    QSoundEffect *soundEffecta1s;
    QSoundEffect *soundEffectb1;
    QSoundEffect *soundEffectc2;
    QSoundEffect *soundEffectc2s;
    QSoundEffect *soundEffectd2;
    QSoundEffect *soundEffectd2s;
    QSoundEffect *soundEffecte2;
    QSoundEffect *soundEffectf2;
    QSoundEffect *soundEffectf2s;
    QSoundEffect *soundEffectg2;
    QSoundEffect *soundEffectg2s;
    QSoundEffect *soundEffecta2;
    QSoundEffect *soundEffecta2s;
    QSoundEffect *soundEffectb2;
    QSoundEffect *soundEffectc3;
    QSoundEffect *soundEffectc3s;
    QSoundEffect *soundEffectd3;
    QSoundEffect *soundEffectd3s;
    QSoundEffect *soundEffecte3;
    QSoundEffect *soundEffectf3;
    QSoundEffect *soundEffectf3s;
    QSoundEffect *soundEffectg3;
    QSoundEffect *soundEffectg3s;
    QSoundEffect *soundEffecta3;
    QSoundEffect *soundEffecta3s;
    QSoundEffect *soundEffectb3;
    QSoundEffect *soundEffectc4;
    QSoundEffect *soundEffectc4s;
    QSoundEffect *soundEffectd4;
    QSoundEffect *soundEffectd4s;
    QSoundEffect *soundEffecte4;
    QSoundEffect *soundEffectf4;
    QSoundEffect *soundEffectf4s;
    QSoundEffect *soundEffectg4;
    QSoundEffect *soundEffectg4s;
    QSoundEffect *soundEffecta4;
    QSoundEffect *soundEffecta4s;
    QSoundEffect *soundEffectb4;
    void initializeSoundEffects();
    void playSoundEffect(QSoundEffect *soundEffect, const QString &baseName);
    void setKeyLabels(const QStringList &labels); // Helper function to set key labels
    QStringList generateKeyLabels(int high); // Function to generate key labels based on high value
    bool isPause;
    bool isRecord;
    QList<QPair<QTime, QString>> recordedKeys;
    void recordKeyPress(const QString &key);
    QTimer *playbackTimer;
    int playbackIndex;
    QTime playbackStartTime;
    QTime recordStartTime;
    QTime pauseTime;
};

#endif // PIANO_H
