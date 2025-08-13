#include <stdio.h>
#include <string.h>

// Define UE (User Equipment)
typedef struct {
    int ue_id;
    char state[50];
} UE;

// Step 1: UE sends preamble
void send_preamble(UE *ue) {
    printf("UE %d: Sending RACH Preamble (Msg1)\n", ue->ue_id);
    strcpy(ue->state, "Preamble Sent");
}

// Step 2: gNB sends RAR
void receive_rar(UE *ue) {
    printf("gNB: Sending Random Access Response (Msg2) to UE %d\n", ue->ue_id);
    strcpy(ue->state, "RAR Received");
}

// Step 3: UE sends RRC Connection Request
void send_rrc_request(UE *ue) {
    printf("UE %d: Sending RRC Connection Request (Msg3)\n", ue->ue_id);
    strcpy(ue->state, "RRC Request Sent");
}

// Step 4: gNB sends RRC Connection Setup
void receive_rrc_setup(UE *ue) {
    printf("gNB: Sending RRC Connection Setup (Msg4) to UE %d\n", ue->ue_id);
    strcpy(ue->state, "Connected");
}

int main() {
    UE ue1 = {101, "Idle"};

    send_preamble(&ue1);
    receive_rar(&ue1);
    send_rrc_request(&ue1);
    receive_rrc_setup(&ue1);

    printf("UE %d final state: %s\n", ue1.ue_id, ue1.state);
    return 0;
}
