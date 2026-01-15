#include "pie-rv32imc-decoder.h"

rv32imc_instruction rv32imc_decode(uint16_t *address) {
  uint16_t instruction = *address;
  if ((instruction & (1 << 1)) == 0) {
    if ((instruction & (1 << 15)) == 0) {
      if ((instruction & (1 << 14)) == 0) {
        if ((instruction & (1 << 13)) == 0) {
          if ((instruction & (1 << 11)) == 0) {
            if ((instruction & (1 << 10)) == 0) {
              if ((instruction & (1 << 9)) == 0) {
                if ((instruction & (1 << 8)) == 0) {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 0000000000000000
                                  return RV32IMC_C_ILLEGAL;
                                } else {
                                  return RV32IMC_INVALID;
                                }
                              } else {
                                return RV32IMC_INVALID;
                              }
                            } else {
                              return RV32IMC_INVALID;
                            }
                          } else {
                            // 00000000001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000000010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000000011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010000000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010000001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010000010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010000011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x00000xxxxx01
                      return RV32IMC_C_NOP;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000000100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000000101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000000110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000000111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010000100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010000101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010000110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010000111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x00001xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000001000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000001001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000001010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000001011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010001000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010001001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010001010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010001011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x00010xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000001100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000001101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000001110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000001111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010001100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010001101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010001110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010001111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x00011xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  }
                }
              } else {
                if ((instruction & (1 << 8)) == 0) {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000010000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000010001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000010010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000010011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010010000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010010001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010010010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010010011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x00100xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000010100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000010101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000010110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000010111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010010100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010010101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010010110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010010111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x00101xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000011000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000011001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000011010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000011011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010011000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010011001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010011010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010011011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x00110xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000011100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000011101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000011110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000011111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010011100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010011101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010011110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010011111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x00111xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  }
                }
              }
            } else {
              if ((instruction & (1 << 9)) == 0) {
                if ((instruction & (1 << 8)) == 0) {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000100000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000100001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000100010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000100011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010100000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010100001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010100010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010100011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x01000xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000100100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000100101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000100110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000100111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010100100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010100101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010100110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010100111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x01001xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000101000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000101001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000101010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000101011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010101000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010101001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010101010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010101011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x01010xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000101100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000101101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000101110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000101111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010101100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010101101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010101110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010101111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x01011xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  }
                }
              } else {
                if ((instruction & (1 << 8)) == 0) {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000110000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000110001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000110010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000110011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010110000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010110001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010110010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010110011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x01100xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000110100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000110101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000110110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000110111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010110100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010110101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010110110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010110111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x01101xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000111000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000111001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000111010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000111011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010111000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010111001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010111010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010111011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x01110xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000111100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000111101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00000111110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00000111111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010111100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010111101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00010111110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00010111111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x01111xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  }
                }
              }
            }
          } else {
            if ((instruction & (1 << 10)) == 0) {
              if ((instruction & (1 << 9)) == 0) {
                if ((instruction & (1 << 8)) == 0) {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001000000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001000001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001000010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001000011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011000000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011000001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011000010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011000011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x10000xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001000100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001000101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001000110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001000111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011000100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011000101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011000110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011000111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x10001xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001001000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001001001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001001010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001001011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011001000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011001001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011001010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011001011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x10010xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001001100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001001101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001001110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001001111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011001100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011001101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011001110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011001111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x10011xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  }
                }
              } else {
                if ((instruction & (1 << 8)) == 0) {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001010000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001010001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001010010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001010011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011010000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011010001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011010010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011010011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x10100xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001010100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001010101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001010110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001010111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011010100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011010101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011010110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011010111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x10101xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001011000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001011001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001011010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001011011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011011000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011011001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011011010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011011011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x10110xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001011100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001011101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001011110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001011111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011011100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011011101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011011110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011011111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x10111xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  }
                }
              }
            } else {
              if ((instruction & (1 << 9)) == 0) {
                if ((instruction & (1 << 8)) == 0) {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001100000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001100001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001100010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001100011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011100000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011100001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011100010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011100011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x11000xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001100100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001100101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001100110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001100111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011100100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011100101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011100110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011100111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x11001xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001101000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001101001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001101010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001101011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011101000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011101001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011101010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011101011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x11010xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001101100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001101101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001101110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001101111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011101100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011101101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011101110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011101111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x11011xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  }
                }
              } else {
                if ((instruction & (1 << 8)) == 0) {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001110000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001110001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001110010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001110011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011110000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011110001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011110010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011110011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x11100xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001110100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001110101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001110110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001110111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011110100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011110101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011110110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011110111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x11101xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001111000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001111001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001111010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001111011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011111000xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011111001xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011111010xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011111011xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x11110xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      if ((instruction & (1 << 12)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001111100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001111101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00001111110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00001111111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011111100xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011111101xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            // 00011111110xxx00
                            return RV32IMC_C_ADDI4SPN;
                          } else {
                            // 00011111111xxx00
                            return RV32IMC_C_ADDI4SPN;
                          }
                        }
                      }
                    } else {
                      // 000x11111xxxxx01
                      return RV32IMC_C_ADDI;
                    }
                  }
                }
              }
            }
          }
        } else {
          if ((instruction & (1 << 0)) == 0) {
            return RV32IMC_INVALID;
          } else {
            // 001xxxxxxxxxxx01
            return RV32IMC_C_JAL;
          }
        }
      } else {
        if ((instruction & (1 << 13)) == 0) {
          if ((instruction & (1 << 0)) == 0) {
            // 010xxxxxxxxxxx00
            return RV32IMC_C_LW;
          } else {
            if ((instruction & (1 << 11)) == 0) {
              if ((instruction & (1 << 10)) == 0) {
                if ((instruction & (1 << 9)) == 0) {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 010x00001xxxxx01
                      return RV32IMC_C_LI;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x00010xxxxx01
                      return RV32IMC_C_LI;
                    } else {
                      // 010x00011xxxxx01
                      return RV32IMC_C_LI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x00100xxxxx01
                      return RV32IMC_C_LI;
                    } else {
                      // 010x00101xxxxx01
                      return RV32IMC_C_LI;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x00110xxxxx01
                      return RV32IMC_C_LI;
                    } else {
                      // 010x00111xxxxx01
                      return RV32IMC_C_LI;
                    }
                  }
                }
              } else {
                if ((instruction & (1 << 9)) == 0) {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x01000xxxxx01
                      return RV32IMC_C_LI;
                    } else {
                      // 010x01001xxxxx01
                      return RV32IMC_C_LI;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x01010xxxxx01
                      return RV32IMC_C_LI;
                    } else {
                      // 010x01011xxxxx01
                      return RV32IMC_C_LI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x01100xxxxx01
                      return RV32IMC_C_LI;
                    } else {
                      // 010x01101xxxxx01
                      return RV32IMC_C_LI;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x01110xxxxx01
                      return RV32IMC_C_LI;
                    } else {
                      // 010x01111xxxxx01
                      return RV32IMC_C_LI;
                    }
                  }
                }
              }
            } else {
              if ((instruction & (1 << 10)) == 0) {
                if ((instruction & (1 << 9)) == 0) {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x10000xxxxx01
                      return RV32IMC_C_LI;
                    } else {
                      // 010x10001xxxxx01
                      return RV32IMC_C_LI;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x10010xxxxx01
                      return RV32IMC_C_LI;
                    } else {
                      // 010x10011xxxxx01
                      return RV32IMC_C_LI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x10100xxxxx01
                      return RV32IMC_C_LI;
                    } else {
                      // 010x10101xxxxx01
                      return RV32IMC_C_LI;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x10110xxxxx01
                      return RV32IMC_C_LI;
                    } else {
                      // 010x10111xxxxx01
                      return RV32IMC_C_LI;
                    }
                  }
                }
              } else {
                if ((instruction & (1 << 9)) == 0) {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x11000xxxxx01
                      return RV32IMC_C_LI;
                    } else {
                      // 010x11001xxxxx01
                      return RV32IMC_C_LI;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x11010xxxxx01
                      return RV32IMC_C_LI;
                    } else {
                      // 010x11011xxxxx01
                      return RV32IMC_C_LI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x11100xxxxx01
                      return RV32IMC_C_LI;
                    } else {
                      // 010x11101xxxxx01
                      return RV32IMC_C_LI;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x11110xxxxx01
                      return RV32IMC_C_LI;
                    } else {
                      // 010x11111xxxxx01
                      return RV32IMC_C_LI;
                    }
                  }
                }
              }
            }
          }
        } else {
          if ((instruction & (1 << 11)) == 0) {
            if ((instruction & (1 << 10)) == 0) {
              if ((instruction & (1 << 9)) == 0) {
                if ((instruction & (1 << 8)) == 0) {
                  if ((instruction & (1 << 7)) == 0) {
                    return RV32IMC_INVALID;
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x00001xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x00010xxxxx01
                      return RV32IMC_C_ADDI16SP;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x00011xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  }
                }
              } else {
                if ((instruction & (1 << 8)) == 0) {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x00100xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x00101xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x00110xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x00111xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  }
                }
              }
            } else {
              if ((instruction & (1 << 9)) == 0) {
                if ((instruction & (1 << 8)) == 0) {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x01000xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x01001xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x01010xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x01011xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  }
                }
              } else {
                if ((instruction & (1 << 8)) == 0) {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x01100xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x01101xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x01110xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x01111xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  }
                }
              }
            }
          } else {
            if ((instruction & (1 << 10)) == 0) {
              if ((instruction & (1 << 9)) == 0) {
                if ((instruction & (1 << 8)) == 0) {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x10000xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x10001xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x10010xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x10011xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  }
                }
              } else {
                if ((instruction & (1 << 8)) == 0) {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x10100xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x10101xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x10110xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x10111xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  }
                }
              }
            } else {
              if ((instruction & (1 << 9)) == 0) {
                if ((instruction & (1 << 8)) == 0) {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x11000xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x11001xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x11010xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x11011xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  }
                }
              } else {
                if ((instruction & (1 << 8)) == 0) {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x11100xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x11101xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 7)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x11110xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 011x11111xxxxx01
                      return RV32IMC_C_LUI;
                    }
                  }
                }
              }
            }
          }
        }
      }
    } else {
      if ((instruction & (1 << 14)) == 0) {
        if ((instruction & (1 << 13)) == 0) {
          if ((instruction & (1 << 11)) == 0) {
            if ((instruction & (1 << 10)) == 0) {
              if ((instruction & (1 << 0)) == 0) {
                return RV32IMC_INVALID;
              } else {
                // 100x00xxxxxxxx01
                return RV32IMC_C_SRLI;
              }
            } else {
              if ((instruction & (1 << 0)) == 0) {
                return RV32IMC_INVALID;
              } else {
                // 100x01xxxxxxxx01
                return RV32IMC_C_SRAI;
              }
            }
          } else {
            if ((instruction & (1 << 10)) == 0) {
              if ((instruction & (1 << 0)) == 0) {
                return RV32IMC_INVALID;
              } else {
                // 100x10xxxxxxxx01
                return RV32IMC_C_ANDI;
              }
            } else {
              if ((instruction & (1 << 12)) == 0) {
                if ((instruction & (1 << 6)) == 0) {
                  if ((instruction & (1 << 5)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 100011xxx00xxx01
                      return RV32IMC_C_SUB;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 100011xxx01xxx01
                      return RV32IMC_C_XOR;
                    }
                  }
                } else {
                  if ((instruction & (1 << 5)) == 0) {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 100011xxx10xxx01
                      return RV32IMC_C_OR;
                    }
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 100011xxx11xxx01
                      return RV32IMC_C_AND;
                    }
                  }
                }
              } else {
                return RV32IMC_INVALID;
              }
            }
          }
        } else {
          if ((instruction & (1 << 0)) == 0) {
            return RV32IMC_INVALID;
          } else {
            // 101xxxxxxxxxxx01
            return RV32IMC_C_J;
          }
        }
      } else {
        if ((instruction & (1 << 13)) == 0) {
          if ((instruction & (1 << 0)) == 0) {
            // 110xxxxxxxxxxx00
            return RV32IMC_C_SW;
          } else {
            // 110xxxxxxxxxxx01
            return RV32IMC_C_BEQZ;
          }
        } else {
          if ((instruction & (1 << 0)) == 0) {
            return RV32IMC_INVALID;
          } else {
            // 111xxxxxxxxxxx01
            return RV32IMC_C_BNEZ;
          }
        }
      }
    }
  } else {
    if ((instruction & (1 << 0)) == 0) {
      if ((instruction & (1 << 15)) == 0) {
        if ((instruction & (1 << 14)) == 0) {
          if ((instruction & (1 << 13)) == 0) {
            if ((instruction & (1 << 11)) == 0) {
              if ((instruction & (1 << 10)) == 0) {
                if ((instruction & (1 << 9)) == 0) {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 000x00001xxxxx10
                      return RV32IMC_C_SLLI;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 000x00010xxxxx10
                      return RV32IMC_C_SLLI;
                    } else {
                      // 000x00011xxxxx10
                      return RV32IMC_C_SLLI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      // 000x00100xxxxx10
                      return RV32IMC_C_SLLI;
                    } else {
                      // 000x00101xxxxx10
                      return RV32IMC_C_SLLI;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 000x00110xxxxx10
                      return RV32IMC_C_SLLI;
                    } else {
                      // 000x00111xxxxx10
                      return RV32IMC_C_SLLI;
                    }
                  }
                }
              } else {
                if ((instruction & (1 << 9)) == 0) {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      // 000x01000xxxxx10
                      return RV32IMC_C_SLLI;
                    } else {
                      // 000x01001xxxxx10
                      return RV32IMC_C_SLLI;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 000x01010xxxxx10
                      return RV32IMC_C_SLLI;
                    } else {
                      // 000x01011xxxxx10
                      return RV32IMC_C_SLLI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      // 000x01100xxxxx10
                      return RV32IMC_C_SLLI;
                    } else {
                      // 000x01101xxxxx10
                      return RV32IMC_C_SLLI;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 000x01110xxxxx10
                      return RV32IMC_C_SLLI;
                    } else {
                      // 000x01111xxxxx10
                      return RV32IMC_C_SLLI;
                    }
                  }
                }
              }
            } else {
              if ((instruction & (1 << 10)) == 0) {
                if ((instruction & (1 << 9)) == 0) {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      // 000x10000xxxxx10
                      return RV32IMC_C_SLLI;
                    } else {
                      // 000x10001xxxxx10
                      return RV32IMC_C_SLLI;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 000x10010xxxxx10
                      return RV32IMC_C_SLLI;
                    } else {
                      // 000x10011xxxxx10
                      return RV32IMC_C_SLLI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      // 000x10100xxxxx10
                      return RV32IMC_C_SLLI;
                    } else {
                      // 000x10101xxxxx10
                      return RV32IMC_C_SLLI;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 000x10110xxxxx10
                      return RV32IMC_C_SLLI;
                    } else {
                      // 000x10111xxxxx10
                      return RV32IMC_C_SLLI;
                    }
                  }
                }
              } else {
                if ((instruction & (1 << 9)) == 0) {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      // 000x11000xxxxx10
                      return RV32IMC_C_SLLI;
                    } else {
                      // 000x11001xxxxx10
                      return RV32IMC_C_SLLI;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 000x11010xxxxx10
                      return RV32IMC_C_SLLI;
                    } else {
                      // 000x11011xxxxx10
                      return RV32IMC_C_SLLI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      // 000x11100xxxxx10
                      return RV32IMC_C_SLLI;
                    } else {
                      // 000x11101xxxxx10
                      return RV32IMC_C_SLLI;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 000x11110xxxxx10
                      return RV32IMC_C_SLLI;
                    } else {
                      // 000x11111xxxxx10
                      return RV32IMC_C_SLLI;
                    }
                  }
                }
              }
            }
          } else {
            return RV32IMC_INVALID;
          }
        } else {
          if ((instruction & (1 << 13)) == 0) {
            if ((instruction & (1 << 11)) == 0) {
              if ((instruction & (1 << 10)) == 0) {
                if ((instruction & (1 << 9)) == 0) {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      return RV32IMC_INVALID;
                    } else {
                      // 010x00001xxxxx10
                      return RV32IMC_C_LWSP;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x00010xxxxx10
                      return RV32IMC_C_LWSP;
                    } else {
                      // 010x00011xxxxx10
                      return RV32IMC_C_LWSP;
                    }
                  }
                } else {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x00100xxxxx10
                      return RV32IMC_C_LWSP;
                    } else {
                      // 010x00101xxxxx10
                      return RV32IMC_C_LWSP;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x00110xxxxx10
                      return RV32IMC_C_LWSP;
                    } else {
                      // 010x00111xxxxx10
                      return RV32IMC_C_LWSP;
                    }
                  }
                }
              } else {
                if ((instruction & (1 << 9)) == 0) {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x01000xxxxx10
                      return RV32IMC_C_LWSP;
                    } else {
                      // 010x01001xxxxx10
                      return RV32IMC_C_LWSP;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x01010xxxxx10
                      return RV32IMC_C_LWSP;
                    } else {
                      // 010x01011xxxxx10
                      return RV32IMC_C_LWSP;
                    }
                  }
                } else {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x01100xxxxx10
                      return RV32IMC_C_LWSP;
                    } else {
                      // 010x01101xxxxx10
                      return RV32IMC_C_LWSP;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x01110xxxxx10
                      return RV32IMC_C_LWSP;
                    } else {
                      // 010x01111xxxxx10
                      return RV32IMC_C_LWSP;
                    }
                  }
                }
              }
            } else {
              if ((instruction & (1 << 10)) == 0) {
                if ((instruction & (1 << 9)) == 0) {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x10000xxxxx10
                      return RV32IMC_C_LWSP;
                    } else {
                      // 010x10001xxxxx10
                      return RV32IMC_C_LWSP;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x10010xxxxx10
                      return RV32IMC_C_LWSP;
                    } else {
                      // 010x10011xxxxx10
                      return RV32IMC_C_LWSP;
                    }
                  }
                } else {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x10100xxxxx10
                      return RV32IMC_C_LWSP;
                    } else {
                      // 010x10101xxxxx10
                      return RV32IMC_C_LWSP;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x10110xxxxx10
                      return RV32IMC_C_LWSP;
                    } else {
                      // 010x10111xxxxx10
                      return RV32IMC_C_LWSP;
                    }
                  }
                }
              } else {
                if ((instruction & (1 << 9)) == 0) {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x11000xxxxx10
                      return RV32IMC_C_LWSP;
                    } else {
                      // 010x11001xxxxx10
                      return RV32IMC_C_LWSP;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x11010xxxxx10
                      return RV32IMC_C_LWSP;
                    } else {
                      // 010x11011xxxxx10
                      return RV32IMC_C_LWSP;
                    }
                  }
                } else {
                  if ((instruction & (1 << 8)) == 0) {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x11100xxxxx10
                      return RV32IMC_C_LWSP;
                    } else {
                      // 010x11101xxxxx10
                      return RV32IMC_C_LWSP;
                    }
                  } else {
                    if ((instruction & (1 << 7)) == 0) {
                      // 010x11110xxxxx10
                      return RV32IMC_C_LWSP;
                    } else {
                      // 010x11111xxxxx10
                      return RV32IMC_C_LWSP;
                    }
                  }
                }
              }
            }
          } else {
            return RV32IMC_INVALID;
          }
        }
      } else {
        if ((instruction & (1 << 14)) == 0) {
          if ((instruction & (1 << 13)) == 0) {
            if ((instruction & (1 << 12)) == 0) {
              if ((instruction & (1 << 11)) == 0) {
                if ((instruction & (1 << 10)) == 0) {
                  if ((instruction & (1 << 9)) == 0) {
                    if ((instruction & (1 << 8)) == 0) {
                      if ((instruction & (1 << 7)) == 0) {
                        return RV32IMC_INVALID;
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000010000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000000010000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000010001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000010001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000010010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000010010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000010011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000010011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000010100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000010100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000010101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000010101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000010110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000010110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000010111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000010111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000011000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000011000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000011001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000011001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000011010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000011010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000011011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000011011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000011100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000011100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000011101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000011101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000011110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000011110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000011111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000011111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      }
                    } else {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000100000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000000100000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000100001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000100001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000100010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000100010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000100011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000100011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000100100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000100100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000100101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000100101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000100110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000100110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000100111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000100111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000101000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000101000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000101001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000101001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000101010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000101010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000101011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000101011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000101100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000101100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000101101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000101101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000101110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000101110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000101111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000101111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000110000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000000110000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000110001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000110001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000110010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000110010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000110011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000110011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000110100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000110100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000110101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000110101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000110110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000110110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000110111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000110111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000111000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000111000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000111001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000111001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000111010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000111010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000111011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000111011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000111100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000111100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000111101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000111101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000111110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000111110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000000111111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000000111111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  } else {
                    if ((instruction & (1 << 8)) == 0) {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001000000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000001000000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001000001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001000001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001000010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001000010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001000011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001000011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001000100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001000100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001000101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001000101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001000110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001000110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001000111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001000111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001001000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001001000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001001001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001001001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001001010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001001010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001001011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001001011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001001100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001001100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001001101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001001101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001001110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001001110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001001111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001001111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001010000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000001010000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001010001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001010001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001010010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001010010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001010011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001010011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001010100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001010100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001010101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001010101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001010110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001010110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001010111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001010111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001011000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001011000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001011001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001011001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001011010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001011010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001011011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001011011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001011100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001011100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001011101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001011101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001011110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001011110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001011111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001011111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      }
                    } else {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001100000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000001100000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001100001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001100001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001100010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001100010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001100011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001100011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001100100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001100100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001100101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001100101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001100110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001100110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001100111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001100111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001101000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001101000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001101001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001101001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001101010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001101010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001101011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001101011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001101100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001101100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001101101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001101101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001101110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001101110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001101111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001101111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001110000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000001110000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001110001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001110001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001110010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001110010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001110011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001110011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001110100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001110100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001110101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001110101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001110110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001110110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001110111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001110111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001111000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001111000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001111001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001111001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001111010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001111010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001111011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001111011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001111100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001111100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001111101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001111101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001111110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001111110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000001111111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000001111111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                } else {
                  if ((instruction & (1 << 9)) == 0) {
                    if ((instruction & (1 << 8)) == 0) {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010000000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000010000000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010000001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010000001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010000010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010000010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010000011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010000011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010000100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010000100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010000101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010000101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010000110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010000110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010000111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010000111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010001000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010001000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010001001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010001001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010001010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010001010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010001011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010001011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010001100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010001100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010001101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010001101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010001110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010001110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010001111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010001111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010010000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000010010000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010010001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010010001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010010010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010010010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010010011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010010011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010010100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010010100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010010101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010010101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010010110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010010110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010010111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010010111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010011000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010011000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010011001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010011001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010011010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010011010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010011011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010011011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010011100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010011100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010011101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010011101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010011110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010011110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010011111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010011111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      }
                    } else {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010100000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000010100000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010100001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010100001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010100010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010100010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010100011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010100011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010100100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010100100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010100101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010100101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010100110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010100110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010100111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010100111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010101000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010101000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010101001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010101001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010101010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010101010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010101011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010101011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010101100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010101100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010101101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010101101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010101110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010101110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010101111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010101111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010110000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000010110000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010110001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010110001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010110010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010110010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010110011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010110011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010110100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010110100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010110101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010110101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010110110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010110110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010110111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010110111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010111000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010111000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010111001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010111001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010111010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010111010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010111011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010111011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010111100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010111100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010111101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010111101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010111110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010111110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000010111111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000010111111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  } else {
                    if ((instruction & (1 << 8)) == 0) {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011000000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000011000000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011000001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011000001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011000010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011000010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011000011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011000011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011000100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011000100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011000101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011000101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011000110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011000110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011000111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011000111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011001000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011001000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011001001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011001001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011001010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011001010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011001011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011001011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011001100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011001100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011001101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011001101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011001110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011001110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011001111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011001111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011010000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000011010000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011010001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011010001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011010010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011010010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011010011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011010011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011010100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011010100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011010101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011010101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011010110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011010110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011010111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011010111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011011000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011011000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011011001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011011001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011011010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011011010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011011011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011011011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011011100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011011100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011011101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011011101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011011110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011011110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011011111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011011111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      }
                    } else {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011100000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000011100000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011100001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011100001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011100010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011100010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011100011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011100011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011100100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011100100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011100101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011100101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011100110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011100110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011100111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011100111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011101000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011101000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011101001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011101001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011101010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011101010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011101011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011101011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011101100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011101100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011101101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011101101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011101110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011101110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011101111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011101111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011110000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000011110000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011110001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011110001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011110010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011110010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011110011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011110011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011110100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011110100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011110101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011110101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011110110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011110110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011110111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011110111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011111000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011111000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011111001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011111001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011111010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011111010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011111011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011111011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011111100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011111100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011111101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011111101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011111110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011111110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000011111111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000011111111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              } else {
                if ((instruction & (1 << 10)) == 0) {
                  if ((instruction & (1 << 9)) == 0) {
                    if ((instruction & (1 << 8)) == 0) {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100000000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000100000000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100000001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100000001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100000010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100000010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100000011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100000011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100000100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100000100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100000101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100000101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100000110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100000110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100000111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100000111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100001000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100001000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100001001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100001001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100001010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100001010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100001011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100001011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100001100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100001100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100001101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100001101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100001110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100001110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100001111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100001111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100010000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000100010000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100010001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100010001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100010010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100010010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100010011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100010011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100010100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100010100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100010101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100010101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100010110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100010110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100010111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100010111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100011000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100011000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100011001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100011001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100011010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100011010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100011011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100011011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100011100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100011100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100011101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100011101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100011110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100011110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100011111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100011111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      }
                    } else {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100100000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000100100000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100100001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100100001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100100010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100100010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100100011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100100011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100100100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100100100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100100101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100100101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100100110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100100110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100100111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100100111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100101000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100101000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100101001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100101001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100101010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100101010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100101011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100101011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100101100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100101100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100101101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100101101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100101110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100101110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100101111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100101111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100110000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000100110000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100110001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100110001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100110010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100110010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100110011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100110011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100110100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100110100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100110101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100110101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100110110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100110110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100110111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100110111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100111000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100111000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100111001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100111001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100111010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100111010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100111011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100111011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100111100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100111100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100111101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100111101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100111110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100111110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000100111111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000100111111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  } else {
                    if ((instruction & (1 << 8)) == 0) {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101000000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000101000000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101000001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101000001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101000010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101000010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101000011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101000011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101000100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101000100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101000101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101000101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101000110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101000110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101000111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101000111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101001000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101001000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101001001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101001001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101001010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101001010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101001011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101001011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101001100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101001100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101001101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101001101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101001110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101001110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101001111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101001111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101010000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000101010000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101010001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101010001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101010010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101010010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101010011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101010011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101010100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101010100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101010101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101010101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101010110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101010110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101010111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101010111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101011000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101011000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101011001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101011001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101011010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101011010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101011011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101011011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101011100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101011100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101011101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101011101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101011110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101011110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101011111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101011111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      }
                    } else {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101100000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000101100000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101100001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101100001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101100010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101100010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101100011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101100011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101100100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101100100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101100101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101100101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101100110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101100110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101100111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101100111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101101000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101101000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101101001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101101001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101101010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101101010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101101011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101101011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101101100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101101100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101101101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101101101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101101110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101101110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101101111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101101111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101110000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000101110000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101110001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101110001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101110010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101110010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101110011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101110011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101110100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101110100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101110101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101110101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101110110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101110110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101110111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101110111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101111000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101111000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101111001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101111001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101111010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101111010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101111011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101111011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101111100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101111100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101111101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101111101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101111110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101111110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000101111111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000101111111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                } else {
                  if ((instruction & (1 << 9)) == 0) {
                    if ((instruction & (1 << 8)) == 0) {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110000000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000110000000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110000001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110000001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110000010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110000010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110000011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110000011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110000100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110000100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110000101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110000101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110000110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110000110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110000111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110000111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110001000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110001000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110001001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110001001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110001010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110001010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110001011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110001011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110001100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110001100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110001101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110001101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110001110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110001110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110001111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110001111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110010000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000110010000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110010001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110010001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110010010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110010010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110010011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110010011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110010100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110010100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110010101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110010101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110010110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110010110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110010111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110010111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110011000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110011000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110011001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110011001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110011010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110011010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110011011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110011011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110011100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110011100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110011101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110011101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110011110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110011110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110011111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110011111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      }
                    } else {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110100000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000110100000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110100001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110100001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110100010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110100010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110100011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110100011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110100100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110100100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110100101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110100101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110100110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110100110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110100111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110100111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110101000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110101000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110101001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110101001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110101010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110101010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110101011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110101011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110101100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110101100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110101101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110101101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110101110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110101110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110101111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110101111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110110000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000110110000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110110001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110110001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110110010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110110010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110110011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110110011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110110100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110110100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110110101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110110101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110110110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110110110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110110111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110110111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110111000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110111000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110111001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110111001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110111010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110111010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110111011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110111011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110111100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110111100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110111101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110111101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110111110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110111110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000110111111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000110111111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  } else {
                    if ((instruction & (1 << 8)) == 0) {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111000000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000111000000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111000001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111000001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111000010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111000010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111000011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111000011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111000100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111000100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111000101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111000101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111000110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111000110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111000111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111000111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111001000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111001000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111001001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111001001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111001010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111001010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111001011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111001011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111001100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111001100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111001101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111001101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111001110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111001110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111001111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111001111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111010000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000111010000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111010001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111010001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111010010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111010010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111010011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111010011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111010100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111010100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111010101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111010101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111010110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111010110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111010111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111010111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111011000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111011000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111011001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111011001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111011010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111011010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111011011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111011011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111011100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111011100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111011101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111011101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111011110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111011110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111011111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111011111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      }
                    } else {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111100000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000111100000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111100001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111100001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111100010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111100010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111100011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111100011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111100100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111100100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111100101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111100101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111100110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111100110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111100111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111100111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111101000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111101000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111101001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111101001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111101010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111101010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111101011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111101011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111101100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111101100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111101101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111101101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111101110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111101110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111101111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111101111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111110000010
                                  return RV32IMC_C_JR;
                                } else {
                                  // 1000111110000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111110001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111110001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111110010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111110010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111110011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111110011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111110100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111110100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111110101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111110101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111110110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111110110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111110111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111110111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111111000010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111111000110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111111001010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111111001110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111111010010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111111010110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111111011010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111111011110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111111100010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111111100110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111111101010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111111101110
                                  return RV32IMC_C_MV;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111111110010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111111110110
                                  return RV32IMC_C_MV;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1000111111111010
                                  return RV32IMC_C_MV;
                                } else {
                                  // 1000111111111110
                                  return RV32IMC_C_MV;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            } else {
              if ((instruction & (1 << 11)) == 0) {
                if ((instruction & (1 << 10)) == 0) {
                  if ((instruction & (1 << 9)) == 0) {
                    if ((instruction & (1 << 8)) == 0) {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000000000010
                                  return RV32IMC_C_EBREAK;
                                } else {
                                  return RV32IMC_INVALID;
                                }
                              } else {
                                return RV32IMC_INVALID;
                              }
                            } else {
                              return RV32IMC_INVALID;
                            }
                          } else {
                            return RV32IMC_INVALID;
                          }
                        } else {
                          return RV32IMC_INVALID;
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000010000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001000010000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000010001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000010001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000010010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000010010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000010011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000010011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000010100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000010100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000010101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000010101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000010110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000010110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000010111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000010111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000011000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000011000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000011001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000011001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000011010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000011010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000011011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000011011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000011100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000011100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000011101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000011101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000011110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000011110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000011111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000011111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      }
                    } else {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000100000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001000100000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000100001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000100001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000100010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000100010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000100011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000100011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000100100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000100100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000100101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000100101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000100110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000100110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000100111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000100111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000101000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000101000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000101001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000101001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000101010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000101010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000101011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000101011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000101100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000101100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000101101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000101101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000101110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000101110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000101111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000101111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000110000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001000110000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000110001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000110001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000110010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000110010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000110011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000110011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000110100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000110100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000110101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000110101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000110110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000110110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000110111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000110111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000111000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000111000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000111001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000111001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000111010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000111010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000111011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000111011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000111100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000111100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000111101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000111101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000111110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000111110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001000111111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001000111111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  } else {
                    if ((instruction & (1 << 8)) == 0) {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001000000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001001000000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001000001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001000001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001000010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001000010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001000011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001000011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001000100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001000100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001000101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001000101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001000110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001000110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001000111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001000111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001001000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001001000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001001001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001001001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001001010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001001010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001001011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001001011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001001100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001001100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001001101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001001101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001001110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001001110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001001111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001001111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001010000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001001010000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001010001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001010001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001010010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001010010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001010011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001010011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001010100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001010100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001010101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001010101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001010110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001010110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001010111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001010111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001011000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001011000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001011001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001011001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001011010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001011010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001011011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001011011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001011100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001011100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001011101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001011101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001011110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001011110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001011111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001011111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      }
                    } else {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001100000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001001100000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001100001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001100001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001100010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001100010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001100011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001100011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001100100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001100100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001100101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001100101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001100110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001100110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001100111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001100111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001101000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001101000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001101001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001101001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001101010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001101010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001101011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001101011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001101100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001101100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001101101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001101101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001101110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001101110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001101111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001101111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001110000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001001110000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001110001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001110001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001110010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001110010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001110011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001110011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001110100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001110100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001110101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001110101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001110110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001110110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001110111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001110111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001111000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001111000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001111001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001111001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001111010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001111010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001111011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001111011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001111100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001111100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001111101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001111101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001111110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001111110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001001111111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001001111111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                } else {
                  if ((instruction & (1 << 9)) == 0) {
                    if ((instruction & (1 << 8)) == 0) {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010000000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001010000000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010000001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010000001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010000010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010000010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010000011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010000011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010000100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010000100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010000101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010000101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010000110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010000110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010000111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010000111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010001000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010001000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010001001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010001001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010001010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010001010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010001011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010001011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010001100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010001100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010001101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010001101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010001110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010001110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010001111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010001111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010010000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001010010000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010010001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010010001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010010010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010010010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010010011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010010011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010010100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010010100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010010101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010010101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010010110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010010110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010010111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010010111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010011000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010011000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010011001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010011001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010011010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010011010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010011011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010011011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010011100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010011100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010011101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010011101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010011110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010011110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010011111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010011111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      }
                    } else {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010100000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001010100000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010100001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010100001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010100010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010100010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010100011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010100011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010100100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010100100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010100101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010100101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010100110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010100110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010100111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010100111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010101000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010101000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010101001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010101001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010101010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010101010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010101011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010101011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010101100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010101100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010101101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010101101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010101110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010101110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010101111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010101111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010110000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001010110000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010110001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010110001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010110010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010110010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010110011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010110011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010110100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010110100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010110101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010110101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010110110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010110110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010110111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010110111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010111000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010111000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010111001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010111001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010111010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010111010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010111011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010111011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010111100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010111100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010111101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010111101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010111110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010111110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001010111111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001010111111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  } else {
                    if ((instruction & (1 << 8)) == 0) {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011000000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001011000000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011000001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011000001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011000010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011000010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011000011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011000011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011000100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011000100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011000101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011000101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011000110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011000110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011000111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011000111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011001000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011001000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011001001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011001001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011001010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011001010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011001011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011001011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011001100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011001100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011001101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011001101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011001110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011001110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011001111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011001111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011010000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001011010000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011010001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011010001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011010010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011010010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011010011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011010011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011010100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011010100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011010101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011010101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011010110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011010110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011010111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011010111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011011000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011011000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011011001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011011001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011011010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011011010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011011011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011011011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011011100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011011100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011011101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011011101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011011110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011011110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011011111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011011111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      }
                    } else {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011100000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001011100000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011100001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011100001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011100010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011100010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011100011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011100011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011100100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011100100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011100101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011100101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011100110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011100110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011100111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011100111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011101000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011101000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011101001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011101001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011101010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011101010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011101011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011101011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011101100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011101100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011101101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011101101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011101110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011101110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011101111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011101111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011110000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001011110000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011110001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011110001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011110010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011110010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011110011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011110011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011110100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011110100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011110101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011110101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011110110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011110110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011110111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011110111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011111000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011111000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011111001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011111001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011111010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011111010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011111011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011111011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011111100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011111100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011111101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011111101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011111110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011111110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001011111111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001011111111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              } else {
                if ((instruction & (1 << 10)) == 0) {
                  if ((instruction & (1 << 9)) == 0) {
                    if ((instruction & (1 << 8)) == 0) {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100000000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001100000000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100000001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100000001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100000010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100000010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100000011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100000011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100000100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100000100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100000101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100000101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100000110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100000110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100000111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100000111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100001000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100001000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100001001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100001001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100001010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100001010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100001011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100001011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100001100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100001100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100001101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100001101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100001110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100001110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100001111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100001111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100010000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001100010000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100010001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100010001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100010010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100010010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100010011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100010011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100010100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100010100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100010101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100010101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100010110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100010110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100010111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100010111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100011000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100011000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100011001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100011001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100011010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100011010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100011011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100011011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100011100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100011100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100011101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100011101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100011110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100011110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100011111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100011111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      }
                    } else {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100100000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001100100000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100100001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100100001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100100010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100100010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100100011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100100011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100100100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100100100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100100101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100100101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100100110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100100110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100100111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100100111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100101000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100101000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100101001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100101001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100101010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100101010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100101011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100101011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100101100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100101100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100101101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100101101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100101110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100101110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100101111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100101111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100110000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001100110000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100110001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100110001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100110010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100110010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100110011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100110011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100110100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100110100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100110101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100110101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100110110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100110110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100110111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100110111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100111000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100111000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100111001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100111001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100111010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100111010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100111011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100111011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100111100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100111100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100111101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100111101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100111110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100111110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001100111111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001100111111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  } else {
                    if ((instruction & (1 << 8)) == 0) {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101000000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001101000000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101000001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101000001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101000010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101000010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101000011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101000011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101000100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101000100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101000101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101000101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101000110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101000110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101000111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101000111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101001000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101001000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101001001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101001001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101001010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101001010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101001011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101001011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101001100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101001100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101001101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101001101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101001110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101001110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101001111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101001111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101010000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001101010000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101010001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101010001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101010010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101010010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101010011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101010011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101010100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101010100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101010101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101010101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101010110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101010110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101010111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101010111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101011000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101011000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101011001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101011001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101011010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101011010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101011011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101011011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101011100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101011100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101011101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101011101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101011110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101011110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101011111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101011111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      }
                    } else {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101100000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001101100000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101100001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101100001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101100010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101100010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101100011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101100011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101100100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101100100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101100101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101100101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101100110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101100110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101100111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101100111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101101000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101101000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101101001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101101001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101101010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101101010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101101011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101101011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101101100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101101100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101101101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101101101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101101110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101101110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101101111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101101111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101110000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001101110000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101110001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101110001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101110010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101110010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101110011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101110011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101110100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101110100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101110101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101110101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101110110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101110110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101110111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101110111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101111000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101111000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101111001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101111001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101111010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101111010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101111011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101111011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101111100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101111100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101111101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101111101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101111110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101111110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001101111111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001101111111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                } else {
                  if ((instruction & (1 << 9)) == 0) {
                    if ((instruction & (1 << 8)) == 0) {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110000000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001110000000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110000001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110000001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110000010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110000010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110000011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110000011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110000100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110000100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110000101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110000101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110000110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110000110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110000111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110000111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110001000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110001000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110001001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110001001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110001010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110001010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110001011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110001011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110001100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110001100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110001101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110001101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110001110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110001110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110001111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110001111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110010000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001110010000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110010001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110010001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110010010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110010010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110010011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110010011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110010100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110010100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110010101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110010101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110010110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110010110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110010111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110010111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110011000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110011000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110011001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110011001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110011010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110011010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110011011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110011011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110011100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110011100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110011101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110011101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110011110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110011110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110011111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110011111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      }
                    } else {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110100000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001110100000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110100001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110100001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110100010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110100010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110100011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110100011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110100100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110100100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110100101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110100101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110100110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110100110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110100111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110100111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110101000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110101000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110101001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110101001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110101010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110101010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110101011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110101011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110101100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110101100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110101101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110101101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110101110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110101110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110101111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110101111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110110000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001110110000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110110001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110110001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110110010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110110010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110110011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110110011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110110100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110110100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110110101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110110101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110110110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110110110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110110111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110110111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110111000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110111000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110111001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110111001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110111010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110111010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110111011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110111011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110111100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110111100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110111101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110111101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110111110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110111110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001110111111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001110111111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  } else {
                    if ((instruction & (1 << 8)) == 0) {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111000000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001111000000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111000001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111000001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111000010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111000010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111000011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111000011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111000100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111000100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111000101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111000101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111000110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111000110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111000111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111000111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111001000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111001000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111001001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111001001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111001010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111001010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111001011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111001011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111001100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111001100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111001101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111001101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111001110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111001110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111001111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111001111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111010000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001111010000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111010001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111010001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111010010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111010010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111010011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111010011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111010100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111010100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111010101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111010101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111010110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111010110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111010111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111010111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111011000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111011000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111011001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111011001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111011010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111011010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111011011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111011011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111011100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111011100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111011101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111011101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111011110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111011110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111011111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111011111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      }
                    } else {
                      if ((instruction & (1 << 7)) == 0) {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111100000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001111100000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111100001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111100001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111100010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111100010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111100011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111100011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111100100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111100100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111100101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111100101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111100110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111100110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111100111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111100111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111101000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111101000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111101001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111101001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111101010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111101010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111101011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111101011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111101100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111101100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111101101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111101101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111101110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111101110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111101111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111101111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if ((instruction & (1 << 6)) == 0) {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111110000010
                                  return RV32IMC_C_JALR;
                                } else {
                                  // 1001111110000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111110001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111110001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111110010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111110010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111110011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111110011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111110100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111110100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111110101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111110101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111110110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111110110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111110111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111110111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 5)) == 0) {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111111000010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111111000110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111111001010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111111001110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111111010010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111111010110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111111011010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111111011110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 4)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111111100010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111111100110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111111101010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111111101110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            } else {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111111110010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111111110110
                                  return RV32IMC_C_ADD;
                                }
                              } else {
                                if ((instruction & (1 << 2)) == 0) {
                                  // 1001111111111010
                                  return RV32IMC_C_ADD;
                                } else {
                                  // 1001111111111110
                                  return RV32IMC_C_ADD;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          } else {
            return RV32IMC_INVALID;
          }
        } else {
          if ((instruction & (1 << 13)) == 0) {
            // 110xxxxxxxxxxx10
            return RV32IMC_C_SWSP;
          } else {
            return RV32IMC_INVALID;
          }
        }
      }
    } else {
      if ((instruction & (1 << 6)) == 0) {
        if ((instruction & (1 << 5)) == 0) {
          if ((instruction & (1 << 4)) == 0) {
            if ((instruction & (1 << 14)) == 0) {
              if ((instruction & (1 << 13)) == 0) {
                if ((instruction & (1 << 12)) == 0) {
                  if ((instruction & (1 << 3)) == 0) {
                    if ((instruction & (1 << 2)) == 0) {
                      // x000xxxxx0000011xxxxxxxxxxxxxxxx
                      return RV32IMC_LB;
                    } else {
                      return RV32IMC_INVALID;
                    }
                  } else {
                    if ((instruction & (1 << 15)) == 0) {
                      if ((instruction & (1 << 11)) == 0) {
                        if ((instruction & (1 << 10)) == 0) {
                          if ((instruction & (1 << 9)) == 0) {
                            if ((instruction & (1 << 8)) == 0) {
                              if ((instruction & (1 << 7)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  return RV32IMC_INVALID;
                                } else {
                                  instruction = *(++address);
                                  if ((instruction & (1 << 3)) == 0) {
                                    if ((instruction & (1 << 2)) == 0) {
                                      if ((instruction & (1 << 1)) == 0) {
                                        if ((instruction & (1 << 0)) == 0) {
                                          // 0000000000001111xxxxxxxxxxxx0000
                                          return RV32IMC_FENCE;
                                        } else {
                                          return RV32IMC_INVALID;
                                        }
                                      } else {
                                        return RV32IMC_INVALID;
                                      }
                                    } else {
                                      return RV32IMC_INVALID;
                                    }
                                  } else {
                                    return RV32IMC_INVALID;
                                  }
                                }
                              } else {
                                return RV32IMC_INVALID;
                              }
                            } else {
                              return RV32IMC_INVALID;
                            }
                          } else {
                            return RV32IMC_INVALID;
                          }
                        } else {
                          return RV32IMC_INVALID;
                        }
                      } else {
                        return RV32IMC_INVALID;
                      }
                    } else {
                      return RV32IMC_INVALID;
                    }
                  }
                } else {
                  if ((instruction & (1 << 3)) == 0) {
                    if ((instruction & (1 << 2)) == 0) {
                      // x001xxxxx0000011xxxxxxxxxxxxxxxx
                      return RV32IMC_LH;
                    } else {
                      return RV32IMC_INVALID;
                    }
                  } else {
                    return RV32IMC_INVALID;
                  }
                }
              } else {
                if ((instruction & (1 << 12)) == 0) {
                  if ((instruction & (1 << 3)) == 0) {
                    if ((instruction & (1 << 2)) == 0) {
                      // x010xxxxx0000011xxxxxxxxxxxxxxxx
                      return RV32IMC_LW;
                    } else {
                      return RV32IMC_INVALID;
                    }
                  } else {
                    return RV32IMC_INVALID;
                  }
                } else {
                  return RV32IMC_INVALID;
                }
              }
            } else {
              if ((instruction & (1 << 13)) == 0) {
                if ((instruction & (1 << 12)) == 0) {
                  if ((instruction & (1 << 3)) == 0) {
                    if ((instruction & (1 << 2)) == 0) {
                      // x100xxxxx0000011xxxxxxxxxxxxxxxx
                      return RV32IMC_LBU;
                    } else {
                      return RV32IMC_INVALID;
                    }
                  } else {
                    return RV32IMC_INVALID;
                  }
                } else {
                  if ((instruction & (1 << 3)) == 0) {
                    if ((instruction & (1 << 2)) == 0) {
                      // x101xxxxx0000011xxxxxxxxxxxxxxxx
                      return RV32IMC_LHU;
                    } else {
                      return RV32IMC_INVALID;
                    }
                  } else {
                    return RV32IMC_INVALID;
                  }
                }
              } else {
                return RV32IMC_INVALID;
              }
            }
          } else {
            if ((instruction & (1 << 3)) == 0) {
              if ((instruction & (1 << 2)) == 0) {
                if ((instruction & (1 << 14)) == 0) {
                  if ((instruction & (1 << 13)) == 0) {
                    if ((instruction & (1 << 12)) == 0) {
                      // x000xxxxx0010011xxxxxxxxxxxxxxxx
                      return RV32IMC_ADDI;
                    } else {
                      instruction = *(++address);
                      if ((instruction & (1 << 15)) == 0) {
                        if ((instruction & (1 << 14)) == 0) {
                          if ((instruction & (1 << 13)) == 0) {
                            if ((instruction & (1 << 12)) == 0) {
                              if ((instruction & (1 << 11)) == 0) {
                                if ((instruction & (1 << 10)) == 0) {
                                  // x001xxxxx0010011000000xxxxxxxxxx
                                  return RV32IMC_SLLI;
                                } else {
                                  return RV32IMC_INVALID;
                                }
                              } else {
                                return RV32IMC_INVALID;
                              }
                            } else {
                              return RV32IMC_INVALID;
                            }
                          } else {
                            return RV32IMC_INVALID;
                          }
                        } else {
                          return RV32IMC_INVALID;
                        }
                      } else {
                        return RV32IMC_INVALID;
                      }
                    }
                  } else {
                    if ((instruction & (1 << 12)) == 0) {
                      // x010xxxxx0010011xxxxxxxxxxxxxxxx
                      return RV32IMC_SLTI;
                    } else {
                      // x011xxxxx0010011xxxxxxxxxxxxxxxx
                      return RV32IMC_SLTIU;
                    }
                  }
                } else {
                  if ((instruction & (1 << 13)) == 0) {
                    if ((instruction & (1 << 12)) == 0) {
                      // x100xxxxx0010011xxxxxxxxxxxxxxxx
                      return RV32IMC_XORI;
                    } else {
                      instruction = *(++address);
                      if ((instruction & (1 << 15)) == 0) {
                        if ((instruction & (1 << 14)) == 0) {
                          if ((instruction & (1 << 13)) == 0) {
                            if ((instruction & (1 << 12)) == 0) {
                              if ((instruction & (1 << 11)) == 0) {
                                if ((instruction & (1 << 10)) == 0) {
                                  // x101xxxxx0010011000000xxxxxxxxxx
                                  return RV32IMC_SRLI;
                                } else {
                                  return RV32IMC_INVALID;
                                }
                              } else {
                                return RV32IMC_INVALID;
                              }
                            } else {
                              return RV32IMC_INVALID;
                            }
                          } else {
                            return RV32IMC_INVALID;
                          }
                        } else {
                          if ((instruction & (1 << 13)) == 0) {
                            if ((instruction & (1 << 12)) == 0) {
                              if ((instruction & (1 << 11)) == 0) {
                                if ((instruction & (1 << 10)) == 0) {
                                  // x101xxxxx0010011010000xxxxxxxxxx
                                  return RV32IMC_SRAI;
                                } else {
                                  return RV32IMC_INVALID;
                                }
                              } else {
                                return RV32IMC_INVALID;
                              }
                            } else {
                              return RV32IMC_INVALID;
                            }
                          } else {
                            return RV32IMC_INVALID;
                          }
                        }
                      } else {
                        return RV32IMC_INVALID;
                      }
                    }
                  } else {
                    if ((instruction & (1 << 12)) == 0) {
                      // x110xxxxx0010011xxxxxxxxxxxxxxxx
                      return RV32IMC_ORI;
                    } else {
                      // x111xxxxx0010011xxxxxxxxxxxxxxxx
                      return RV32IMC_ANDI;
                    }
                  }
                }
              } else {
                // xxxxxxxxx0010111xxxxxxxxxxxxxxxx
                return RV32IMC_AUIPC;
              }
            } else {
              return RV32IMC_INVALID;
            }
          }
        } else {
          if ((instruction & (1 << 4)) == 0) {
            if ((instruction & (1 << 14)) == 0) {
              if ((instruction & (1 << 13)) == 0) {
                if ((instruction & (1 << 12)) == 0) {
                  if ((instruction & (1 << 3)) == 0) {
                    if ((instruction & (1 << 2)) == 0) {
                      // x000xxxxx0100011xxxxxxxxxxxxxxxx
                      return RV32IMC_SB;
                    } else {
                      return RV32IMC_INVALID;
                    }
                  } else {
                    return RV32IMC_INVALID;
                  }
                } else {
                  if ((instruction & (1 << 3)) == 0) {
                    if ((instruction & (1 << 2)) == 0) {
                      // x001xxxxx0100011xxxxxxxxxxxxxxxx
                      return RV32IMC_SH;
                    } else {
                      return RV32IMC_INVALID;
                    }
                  } else {
                    return RV32IMC_INVALID;
                  }
                }
              } else {
                if ((instruction & (1 << 12)) == 0) {
                  if ((instruction & (1 << 3)) == 0) {
                    if ((instruction & (1 << 2)) == 0) {
                      // x010xxxxx0100011xxxxxxxxxxxxxxxx
                      return RV32IMC_SW;
                    } else {
                      return RV32IMC_INVALID;
                    }
                  } else {
                    return RV32IMC_INVALID;
                  }
                } else {
                  return RV32IMC_INVALID;
                }
              }
            } else {
              return RV32IMC_INVALID;
            }
          } else {
            if ((instruction & (1 << 3)) == 0) {
              if ((instruction & (1 << 2)) == 0) {
                if ((instruction & (1 << 14)) == 0) {
                  if ((instruction & (1 << 13)) == 0) {
                    if ((instruction & (1 << 12)) == 0) {
                      instruction = *(++address);
                      if ((instruction & (1 << 15)) == 0) {
                        if ((instruction & (1 << 14)) == 0) {
                          if ((instruction & (1 << 13)) == 0) {
                            if ((instruction & (1 << 12)) == 0) {
                              if ((instruction & (1 << 11)) == 0) {
                                if ((instruction & (1 << 10)) == 0) {
                                  if ((instruction & (1 << 9)) == 0) {
                                    // x000xxxxx01100110000000xxxxxxxxx
                                    return RV32IMC_ADD;
                                  } else {
                                    // x000xxxxx01100110000001xxxxxxxxx
                                    return RV32IMC_MUL;
                                  }
                                } else {
                                  return RV32IMC_INVALID;
                                }
                              } else {
                                return RV32IMC_INVALID;
                              }
                            } else {
                              return RV32IMC_INVALID;
                            }
                          } else {
                            return RV32IMC_INVALID;
                          }
                        } else {
                          if ((instruction & (1 << 13)) == 0) {
                            if ((instruction & (1 << 12)) == 0) {
                              if ((instruction & (1 << 11)) == 0) {
                                if ((instruction & (1 << 10)) == 0) {
                                  if ((instruction & (1 << 9)) == 0) {
                                    // x000xxxxx01100110100000xxxxxxxxx
                                    return RV32IMC_SUB;
                                  } else {
                                    return RV32IMC_INVALID;
                                  }
                                } else {
                                  return RV32IMC_INVALID;
                                }
                              } else {
                                return RV32IMC_INVALID;
                              }
                            } else {
                              return RV32IMC_INVALID;
                            }
                          } else {
                            return RV32IMC_INVALID;
                          }
                        }
                      } else {
                        return RV32IMC_INVALID;
                      }
                    } else {
                      instruction = *(++address);
                      if ((instruction & (1 << 15)) == 0) {
                        if ((instruction & (1 << 14)) == 0) {
                          if ((instruction & (1 << 13)) == 0) {
                            if ((instruction & (1 << 12)) == 0) {
                              if ((instruction & (1 << 11)) == 0) {
                                if ((instruction & (1 << 10)) == 0) {
                                  if ((instruction & (1 << 9)) == 0) {
                                    // x001xxxxx01100110000000xxxxxxxxx
                                    return RV32IMC_SLL;
                                  } else {
                                    // x001xxxxx01100110000001xxxxxxxxx
                                    return RV32IMC_MULH;
                                  }
                                } else {
                                  return RV32IMC_INVALID;
                                }
                              } else {
                                return RV32IMC_INVALID;
                              }
                            } else {
                              return RV32IMC_INVALID;
                            }
                          } else {
                            return RV32IMC_INVALID;
                          }
                        } else {
                          return RV32IMC_INVALID;
                        }
                      } else {
                        return RV32IMC_INVALID;
                      }
                    }
                  } else {
                    if ((instruction & (1 << 12)) == 0) {
                      instruction = *(++address);
                      if ((instruction & (1 << 15)) == 0) {
                        if ((instruction & (1 << 14)) == 0) {
                          if ((instruction & (1 << 13)) == 0) {
                            if ((instruction & (1 << 12)) == 0) {
                              if ((instruction & (1 << 11)) == 0) {
                                if ((instruction & (1 << 10)) == 0) {
                                  if ((instruction & (1 << 9)) == 0) {
                                    // x010xxxxx01100110000000xxxxxxxxx
                                    return RV32IMC_SLT;
                                  } else {
                                    // x010xxxxx01100110000001xxxxxxxxx
                                    return RV32IMC_MULHSU;
                                  }
                                } else {
                                  return RV32IMC_INVALID;
                                }
                              } else {
                                return RV32IMC_INVALID;
                              }
                            } else {
                              return RV32IMC_INVALID;
                            }
                          } else {
                            return RV32IMC_INVALID;
                          }
                        } else {
                          return RV32IMC_INVALID;
                        }
                      } else {
                        return RV32IMC_INVALID;
                      }
                    } else {
                      instruction = *(++address);
                      if ((instruction & (1 << 15)) == 0) {
                        if ((instruction & (1 << 14)) == 0) {
                          if ((instruction & (1 << 13)) == 0) {
                            if ((instruction & (1 << 12)) == 0) {
                              if ((instruction & (1 << 11)) == 0) {
                                if ((instruction & (1 << 10)) == 0) {
                                  if ((instruction & (1 << 9)) == 0) {
                                    // x011xxxxx01100110000000xxxxxxxxx
                                    return RV32IMC_SLTU;
                                  } else {
                                    // x011xxxxx01100110000001xxxxxxxxx
                                    return RV32IMC_MULHU;
                                  }
                                } else {
                                  return RV32IMC_INVALID;
                                }
                              } else {
                                return RV32IMC_INVALID;
                              }
                            } else {
                              return RV32IMC_INVALID;
                            }
                          } else {
                            return RV32IMC_INVALID;
                          }
                        } else {
                          return RV32IMC_INVALID;
                        }
                      } else {
                        return RV32IMC_INVALID;
                      }
                    }
                  }
                } else {
                  if ((instruction & (1 << 13)) == 0) {
                    if ((instruction & (1 << 12)) == 0) {
                      instruction = *(++address);
                      if ((instruction & (1 << 15)) == 0) {
                        if ((instruction & (1 << 14)) == 0) {
                          if ((instruction & (1 << 13)) == 0) {
                            if ((instruction & (1 << 12)) == 0) {
                              if ((instruction & (1 << 11)) == 0) {
                                if ((instruction & (1 << 10)) == 0) {
                                  if ((instruction & (1 << 9)) == 0) {
                                    // x100xxxxx01100110000000xxxxxxxxx
                                    return RV32IMC_XOR;
                                  } else {
                                    // x100xxxxx01100110000001xxxxxxxxx
                                    return RV32IMC_DIV;
                                  }
                                } else {
                                  return RV32IMC_INVALID;
                                }
                              } else {
                                return RV32IMC_INVALID;
                              }
                            } else {
                              return RV32IMC_INVALID;
                            }
                          } else {
                            return RV32IMC_INVALID;
                          }
                        } else {
                          return RV32IMC_INVALID;
                        }
                      } else {
                        return RV32IMC_INVALID;
                      }
                    } else {
                      instruction = *(++address);
                      if ((instruction & (1 << 15)) == 0) {
                        if ((instruction & (1 << 14)) == 0) {
                          if ((instruction & (1 << 13)) == 0) {
                            if ((instruction & (1 << 12)) == 0) {
                              if ((instruction & (1 << 11)) == 0) {
                                if ((instruction & (1 << 10)) == 0) {
                                  if ((instruction & (1 << 9)) == 0) {
                                    // x101xxxxx01100110000000xxxxxxxxx
                                    return RV32IMC_SRL;
                                  } else {
                                    // x101xxxxx01100110000001xxxxxxxxx
                                    return RV32IMC_DIVU;
                                  }
                                } else {
                                  return RV32IMC_INVALID;
                                }
                              } else {
                                return RV32IMC_INVALID;
                              }
                            } else {
                              return RV32IMC_INVALID;
                            }
                          } else {
                            return RV32IMC_INVALID;
                          }
                        } else {
                          if ((instruction & (1 << 13)) == 0) {
                            if ((instruction & (1 << 12)) == 0) {
                              if ((instruction & (1 << 11)) == 0) {
                                if ((instruction & (1 << 10)) == 0) {
                                  if ((instruction & (1 << 9)) == 0) {
                                    // x101xxxxx01100110100000xxxxxxxxx
                                    return RV32IMC_SRA;
                                  } else {
                                    return RV32IMC_INVALID;
                                  }
                                } else {
                                  return RV32IMC_INVALID;
                                }
                              } else {
                                return RV32IMC_INVALID;
                              }
                            } else {
                              return RV32IMC_INVALID;
                            }
                          } else {
                            return RV32IMC_INVALID;
                          }
                        }
                      } else {
                        return RV32IMC_INVALID;
                      }
                    }
                  } else {
                    if ((instruction & (1 << 12)) == 0) {
                      instruction = *(++address);
                      if ((instruction & (1 << 15)) == 0) {
                        if ((instruction & (1 << 14)) == 0) {
                          if ((instruction & (1 << 13)) == 0) {
                            if ((instruction & (1 << 12)) == 0) {
                              if ((instruction & (1 << 11)) == 0) {
                                if ((instruction & (1 << 10)) == 0) {
                                  if ((instruction & (1 << 9)) == 0) {
                                    // x110xxxxx01100110000000xxxxxxxxx
                                    return RV32IMC_OR;
                                  } else {
                                    // x110xxxxx01100110000001xxxxxxxxx
                                    return RV32IMC_REM;
                                  }
                                } else {
                                  return RV32IMC_INVALID;
                                }
                              } else {
                                return RV32IMC_INVALID;
                              }
                            } else {
                              return RV32IMC_INVALID;
                            }
                          } else {
                            return RV32IMC_INVALID;
                          }
                        } else {
                          return RV32IMC_INVALID;
                        }
                      } else {
                        return RV32IMC_INVALID;
                      }
                    } else {
                      instruction = *(++address);
                      if ((instruction & (1 << 15)) == 0) {
                        if ((instruction & (1 << 14)) == 0) {
                          if ((instruction & (1 << 13)) == 0) {
                            if ((instruction & (1 << 12)) == 0) {
                              if ((instruction & (1 << 11)) == 0) {
                                if ((instruction & (1 << 10)) == 0) {
                                  if ((instruction & (1 << 9)) == 0) {
                                    // x111xxxxx01100110000000xxxxxxxxx
                                    return RV32IMC_AND;
                                  } else {
                                    // x111xxxxx01100110000001xxxxxxxxx
                                    return RV32IMC_REMU;
                                  }
                                } else {
                                  return RV32IMC_INVALID;
                                }
                              } else {
                                return RV32IMC_INVALID;
                              }
                            } else {
                              return RV32IMC_INVALID;
                            }
                          } else {
                            return RV32IMC_INVALID;
                          }
                        } else {
                          return RV32IMC_INVALID;
                        }
                      } else {
                        return RV32IMC_INVALID;
                      }
                    }
                  }
                }
              } else {
                // xxxxxxxxx0110111xxxxxxxxxxxxxxxx
                return RV32IMC_LUI;
              }
            } else {
              return RV32IMC_INVALID;
            }
          }
        }
      } else {
        if ((instruction & (1 << 5)) == 0) {
          return RV32IMC_INVALID;
        } else {
          if ((instruction & (1 << 4)) == 0) {
            if ((instruction & (1 << 3)) == 0) {
              if ((instruction & (1 << 14)) == 0) {
                if ((instruction & (1 << 13)) == 0) {
                  if ((instruction & (1 << 12)) == 0) {
                    if ((instruction & (1 << 2)) == 0) {
                      // x000xxxxx1100011xxxxxxxxxxxxxxxx
                      return RV32IMC_BEQ;
                    } else {
                      // x000xxxxx1100111xxxxxxxxxxxxxxxx
                      return RV32IMC_JALR;
                    }
                  } else {
                    if ((instruction & (1 << 2)) == 0) {
                      // x001xxxxx1100011xxxxxxxxxxxxxxxx
                      return RV32IMC_BNE;
                    } else {
                      return RV32IMC_INVALID;
                    }
                  }
                } else {
                  return RV32IMC_INVALID;
                }
              } else {
                if ((instruction & (1 << 13)) == 0) {
                  if ((instruction & (1 << 12)) == 0) {
                    if ((instruction & (1 << 2)) == 0) {
                      // x100xxxxx1100011xxxxxxxxxxxxxxxx
                      return RV32IMC_BLT;
                    } else {
                      return RV32IMC_INVALID;
                    }
                  } else {
                    if ((instruction & (1 << 2)) == 0) {
                      // x101xxxxx1100011xxxxxxxxxxxxxxxx
                      return RV32IMC_BGE;
                    } else {
                      return RV32IMC_INVALID;
                    }
                  }
                } else {
                  if ((instruction & (1 << 12)) == 0) {
                    if ((instruction & (1 << 2)) == 0) {
                      // x110xxxxx1100011xxxxxxxxxxxxxxxx
                      return RV32IMC_BLTU;
                    } else {
                      return RV32IMC_INVALID;
                    }
                  } else {
                    if ((instruction & (1 << 2)) == 0) {
                      // x111xxxxx1100011xxxxxxxxxxxxxxxx
                      return RV32IMC_BGEU;
                    } else {
                      return RV32IMC_INVALID;
                    }
                  }
                }
              }
            } else {
              if ((instruction & (1 << 2)) == 0) {
                return RV32IMC_INVALID;
              } else {
                // xxxxxxxxx1101111xxxxxxxxxxxxxxxx
                return RV32IMC_JAL;
              }
            }
          } else {
            if ((instruction & (1 << 14)) == 0) {
              if ((instruction & (1 << 13)) == 0) {
                if ((instruction & (1 << 12)) == 0) {
                  if ((instruction & (1 << 15)) == 0) {
                    if ((instruction & (1 << 11)) == 0) {
                      if ((instruction & (1 << 10)) == 0) {
                        if ((instruction & (1 << 9)) == 0) {
                          if ((instruction & (1 << 8)) == 0) {
                            if ((instruction & (1 << 7)) == 0) {
                              if ((instruction & (1 << 3)) == 0) {
                                if ((instruction & (1 << 2)) == 0) {
                                  instruction = *(++address);
                                  if ((instruction & (1 << 15)) == 0) {
                                    if ((instruction & (1 << 14)) == 0) {
                                      if ((instruction & (1 << 13)) == 0) {
                                        if ((instruction & (1 << 12)) == 0) {
                                          if ((instruction & (1 << 11)) == 0) {
                                            if ((instruction & (1 << 10)) == 0) {
                                              if ((instruction & (1 << 9)) == 0) {
                                                if ((instruction & (1 << 8)) == 0) {
                                                  if ((instruction & (1 << 7)) == 0) {
                                                    if ((instruction & (1 << 6)) == 0) {
                                                      if ((instruction & (1 << 5)) == 0) {
                                                        if ((instruction & (1 << 4)) == 0) {
                                                          if ((instruction & (1 << 3)) == 0) {
                                                            if ((instruction & (1 << 2)) == 0) {
                                                              if ((instruction & (1 << 1)) == 0) {
                                                                if ((instruction & (1 << 0)) == 0) {
                                                                  // 00000000011100110000000000000000
                                                                  return RV32IMC_ECALL;
                                                                } else {
                                                                  return RV32IMC_INVALID;
                                                                }
                                                              } else {
                                                                return RV32IMC_INVALID;
                                                              }
                                                            } else {
                                                              return RV32IMC_INVALID;
                                                            }
                                                          } else {
                                                            return RV32IMC_INVALID;
                                                          }
                                                        } else {
                                                          if ((instruction & (1 << 3)) == 0) {
                                                            if ((instruction & (1 << 2)) == 0) {
                                                              if ((instruction & (1 << 1)) == 0) {
                                                                if ((instruction & (1 << 0)) == 0) {
                                                                  // 00000000011100110000000000010000
                                                                  return RV32IMC_EBREAK;
                                                                } else {
                                                                  return RV32IMC_INVALID;
                                                                }
                                                              } else {
                                                                return RV32IMC_INVALID;
                                                              }
                                                            } else {
                                                              return RV32IMC_INVALID;
                                                            }
                                                          } else {
                                                            return RV32IMC_INVALID;
                                                          }
                                                        }
                                                      } else {
                                                        return RV32IMC_INVALID;
                                                      }
                                                    } else {
                                                      return RV32IMC_INVALID;
                                                    }
                                                  } else {
                                                    return RV32IMC_INVALID;
                                                  }
                                                } else {
                                                  return RV32IMC_INVALID;
                                                }
                                              } else {
                                                return RV32IMC_INVALID;
                                              }
                                            } else {
                                              return RV32IMC_INVALID;
                                            }
                                          } else {
                                            return RV32IMC_INVALID;
                                          }
                                        } else {
                                          return RV32IMC_INVALID;
                                        }
                                      } else {
                                        if ((instruction & (1 << 12)) == 0) {
                                          return RV32IMC_INVALID;
                                        } else {
                                          if ((instruction & (1 << 11)) == 0) {
                                            if ((instruction & (1 << 10)) == 0) {
                                              if ((instruction & (1 << 9)) == 0) {
                                                if ((instruction & (1 << 8)) == 0) {
                                                  if ((instruction & (1 << 7)) == 0) {
                                                    if ((instruction & (1 << 6)) == 0) {
                                                      if ((instruction & (1 << 5)) == 0) {
                                                        return RV32IMC_INVALID;
                                                      } else {
                                                        if ((instruction & (1 << 4)) == 0) {
                                                          if ((instruction & (1 << 3)) == 0) {
                                                            if ((instruction & (1 << 2)) == 0) {
                                                              if ((instruction & (1 << 1)) == 0) {
                                                                if ((instruction & (1 << 0)) == 0) {
                                                                  // 00000000011100110011000000100000
                                                                  return RV32IMC_MRET;
                                                                } else {
                                                                  return RV32IMC_INVALID;
                                                                }
                                                              } else {
                                                                return RV32IMC_INVALID;
                                                              }
                                                            } else {
                                                              return RV32IMC_INVALID;
                                                            }
                                                          } else {
                                                            return RV32IMC_INVALID;
                                                          }
                                                        } else {
                                                          return RV32IMC_INVALID;
                                                        }
                                                      }
                                                    } else {
                                                      return RV32IMC_INVALID;
                                                    }
                                                  } else {
                                                    return RV32IMC_INVALID;
                                                  }
                                                } else {
                                                  return RV32IMC_INVALID;
                                                }
                                              } else {
                                                return RV32IMC_INVALID;
                                              }
                                            } else {
                                              return RV32IMC_INVALID;
                                            }
                                          } else {
                                            return RV32IMC_INVALID;
                                          }
                                        }
                                      }
                                    } else {
                                      return RV32IMC_INVALID;
                                    }
                                  } else {
                                    return RV32IMC_INVALID;
                                  }
                                } else {
                                  return RV32IMC_INVALID;
                                }
                              } else {
                                return RV32IMC_INVALID;
                              }
                            } else {
                              return RV32IMC_INVALID;
                            }
                          } else {
                            return RV32IMC_INVALID;
                          }
                        } else {
                          return RV32IMC_INVALID;
                        }
                      } else {
                        return RV32IMC_INVALID;
                      }
                    } else {
                      return RV32IMC_INVALID;
                    }
                  } else {
                    return RV32IMC_INVALID;
                  }
                } else {
                  if ((instruction & (1 << 3)) == 0) {
                    if ((instruction & (1 << 2)) == 0) {
                      // x001xxxxx1110011xxxxxxxxxxxxxxxx
                      return RV32IMC_CSRRW;
                    } else {
                      return RV32IMC_INVALID;
                    }
                  } else {
                    return RV32IMC_INVALID;
                  }
                }
              } else {
                if ((instruction & (1 << 12)) == 0) {
                  if ((instruction & (1 << 3)) == 0) {
                    if ((instruction & (1 << 2)) == 0) {
                      // x010xxxxx1110011xxxxxxxxxxxxxxxx
                      return RV32IMC_CSRRS;
                    } else {
                      return RV32IMC_INVALID;
                    }
                  } else {
                    return RV32IMC_INVALID;
                  }
                } else {
                  if ((instruction & (1 << 3)) == 0) {
                    if ((instruction & (1 << 2)) == 0) {
                      // x011xxxxx1110011xxxxxxxxxxxxxxxx
                      return RV32IMC_CSRRC;
                    } else {
                      return RV32IMC_INVALID;
                    }
                  } else {
                    return RV32IMC_INVALID;
                  }
                }
              }
            } else {
              if ((instruction & (1 << 13)) == 0) {
                if ((instruction & (1 << 12)) == 0) {
                  return RV32IMC_INVALID;
                } else {
                  if ((instruction & (1 << 3)) == 0) {
                    if ((instruction & (1 << 2)) == 0) {
                      // x101xxxxx1110011xxxxxxxxxxxxxxxx
                      return RV32IMC_CSRRWI;
                    } else {
                      return RV32IMC_INVALID;
                    }
                  } else {
                    return RV32IMC_INVALID;
                  }
                }
              } else {
                if ((instruction & (1 << 12)) == 0) {
                  if ((instruction & (1 << 3)) == 0) {
                    if ((instruction & (1 << 2)) == 0) {
                      // x110xxxxx1110011xxxxxxxxxxxxxxxx
                      return RV32IMC_CSRRSI;
                    } else {
                      return RV32IMC_INVALID;
                    }
                  } else {
                    return RV32IMC_INVALID;
                  }
                } else {
                  if ((instruction & (1 << 3)) == 0) {
                    if ((instruction & (1 << 2)) == 0) {
                      // x111xxxxx1110011xxxxxxxxxxxxxxxx
                      return RV32IMC_CSRRCI;
                    } else {
                      return RV32IMC_INVALID;
                    }
                  } else {
                    return RV32IMC_INVALID;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
