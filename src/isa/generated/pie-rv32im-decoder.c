#include "pie-rv32im-decoder.h"

rv32im_instruction rv32im_decode(uint32_t *address) {
  uint32_t instruction = *address;
  if ((instruction & (1 << 6)) == 0) {
    if ((instruction & (1 << 5)) == 0) {
      if ((instruction & (1 << 4)) == 0) {
        if ((instruction & (1 << 14)) == 0) {
          if ((instruction & (1 << 13)) == 0) {
            if ((instruction & (1 << 12)) == 0) {
              if ((instruction & (1 << 3)) == 0) {
                if ((instruction & (1 << 2)) == 0) {
                  if ((instruction & (1 << 1)) == 0) {
                    return RV32IM_INVALID;
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IM_INVALID;
                    } else {
                      // xxxxxxxxxxxxxxxxx000xxxxx0000011
                      return RV32IM_LB;
                    }
                  }
                } else {
                  return RV32IM_INVALID;
                }
              } else {
                if ((instruction & (1 << 19)) == 0) {
                  if ((instruction & (1 << 18)) == 0) {
                    if ((instruction & (1 << 17)) == 0) {
                      if ((instruction & (1 << 16)) == 0) {
                        if ((instruction & (1 << 15)) == 0) {
                          if ((instruction & (1 << 11)) == 0) {
                            if ((instruction & (1 << 10)) == 0) {
                              if ((instruction & (1 << 9)) == 0) {
                                if ((instruction & (1 << 8)) == 0) {
                                  if ((instruction & (1 << 7)) == 0) {
                                    if ((instruction & (1 << 2)) == 0) {
                                      return RV32IM_INVALID;
                                    } else {
                                      if ((instruction & (1 << 1)) == 0) {
                                        return RV32IM_INVALID;
                                      } else {
                                        if ((instruction & (1 << 0)) == 0) {
                                          return RV32IM_INVALID;
                                        } else {
                                          // xxxxxxxxxxxx00000000000000001111
                                          return RV32IM_FENCE;
                                        }
                                      }
                                    }
                                  } else {
                                    return RV32IM_INVALID;
                                  }
                                } else {
                                  return RV32IM_INVALID;
                                }
                              } else {
                                return RV32IM_INVALID;
                              }
                            } else {
                              return RV32IM_INVALID;
                            }
                          } else {
                            return RV32IM_INVALID;
                          }
                        } else {
                          return RV32IM_INVALID;
                        }
                      } else {
                        return RV32IM_INVALID;
                      }
                    } else {
                      return RV32IM_INVALID;
                    }
                  } else {
                    return RV32IM_INVALID;
                  }
                } else {
                  return RV32IM_INVALID;
                }
              }
            } else {
              if ((instruction & (1 << 3)) == 0) {
                if ((instruction & (1 << 2)) == 0) {
                  if ((instruction & (1 << 1)) == 0) {
                    return RV32IM_INVALID;
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IM_INVALID;
                    } else {
                      // xxxxxxxxxxxxxxxxx001xxxxx0000011
                      return RV32IM_LH;
                    }
                  }
                } else {
                  return RV32IM_INVALID;
                }
              } else {
                return RV32IM_INVALID;
              }
            }
          } else {
            if ((instruction & (1 << 12)) == 0) {
              if ((instruction & (1 << 3)) == 0) {
                if ((instruction & (1 << 2)) == 0) {
                  if ((instruction & (1 << 1)) == 0) {
                    return RV32IM_INVALID;
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IM_INVALID;
                    } else {
                      // xxxxxxxxxxxxxxxxx010xxxxx0000011
                      return RV32IM_LW;
                    }
                  }
                } else {
                  return RV32IM_INVALID;
                }
              } else {
                return RV32IM_INVALID;
              }
            } else {
              return RV32IM_INVALID;
            }
          }
        } else {
          if ((instruction & (1 << 13)) == 0) {
            if ((instruction & (1 << 12)) == 0) {
              if ((instruction & (1 << 3)) == 0) {
                if ((instruction & (1 << 2)) == 0) {
                  if ((instruction & (1 << 1)) == 0) {
                    return RV32IM_INVALID;
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IM_INVALID;
                    } else {
                      // xxxxxxxxxxxxxxxxx100xxxxx0000011
                      return RV32IM_LBU;
                    }
                  }
                } else {
                  return RV32IM_INVALID;
                }
              } else {
                return RV32IM_INVALID;
              }
            } else {
              if ((instruction & (1 << 3)) == 0) {
                if ((instruction & (1 << 2)) == 0) {
                  if ((instruction & (1 << 1)) == 0) {
                    return RV32IM_INVALID;
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IM_INVALID;
                    } else {
                      // xxxxxxxxxxxxxxxxx101xxxxx0000011
                      return RV32IM_LHU;
                    }
                  }
                } else {
                  return RV32IM_INVALID;
                }
              } else {
                return RV32IM_INVALID;
              }
            }
          } else {
            return RV32IM_INVALID;
          }
        }
      } else {
        if ((instruction & (1 << 3)) == 0) {
          if ((instruction & (1 << 2)) == 0) {
            if ((instruction & (1 << 14)) == 0) {
              if ((instruction & (1 << 13)) == 0) {
                if ((instruction & (1 << 12)) == 0) {
                  if ((instruction & (1 << 1)) == 0) {
                    return RV32IM_INVALID;
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IM_INVALID;
                    } else {
                      // xxxxxxxxxxxxxxxxx000xxxxx0010011
                      return RV32IM_ADDI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 31)) == 0) {
                    if ((instruction & (1 << 30)) == 0) {
                      if ((instruction & (1 << 29)) == 0) {
                        if ((instruction & (1 << 28)) == 0) {
                          if ((instruction & (1 << 27)) == 0) {
                            if ((instruction & (1 << 26)) == 0) {
                              if ((instruction & (1 << 1)) == 0) {
                                return RV32IM_INVALID;
                              } else {
                                if ((instruction & (1 << 0)) == 0) {
                                  return RV32IM_INVALID;
                                } else {
                                  // 000000xxxxxxxxxxx001xxxxx0010011
                                  return RV32IM_SLLI;
                                }
                              }
                            } else {
                              return RV32IM_INVALID;
                            }
                          } else {
                            return RV32IM_INVALID;
                          }
                        } else {
                          return RV32IM_INVALID;
                        }
                      } else {
                        return RV32IM_INVALID;
                      }
                    } else {
                      return RV32IM_INVALID;
                    }
                  } else {
                    return RV32IM_INVALID;
                  }
                }
              } else {
                if ((instruction & (1 << 12)) == 0) {
                  if ((instruction & (1 << 1)) == 0) {
                    return RV32IM_INVALID;
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IM_INVALID;
                    } else {
                      // xxxxxxxxxxxxxxxxx010xxxxx0010011
                      return RV32IM_SLTI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 1)) == 0) {
                    return RV32IM_INVALID;
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IM_INVALID;
                    } else {
                      // xxxxxxxxxxxxxxxxx011xxxxx0010011
                      return RV32IM_SLTIU;
                    }
                  }
                }
              }
            } else {
              if ((instruction & (1 << 13)) == 0) {
                if ((instruction & (1 << 12)) == 0) {
                  if ((instruction & (1 << 1)) == 0) {
                    return RV32IM_INVALID;
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IM_INVALID;
                    } else {
                      // xxxxxxxxxxxxxxxxx100xxxxx0010011
                      return RV32IM_XORI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 31)) == 0) {
                    if ((instruction & (1 << 30)) == 0) {
                      if ((instruction & (1 << 29)) == 0) {
                        if ((instruction & (1 << 28)) == 0) {
                          if ((instruction & (1 << 27)) == 0) {
                            if ((instruction & (1 << 26)) == 0) {
                              if ((instruction & (1 << 1)) == 0) {
                                return RV32IM_INVALID;
                              } else {
                                if ((instruction & (1 << 0)) == 0) {
                                  return RV32IM_INVALID;
                                } else {
                                  // 000000xxxxxxxxxxx101xxxxx0010011
                                  return RV32IM_SRLI;
                                }
                              }
                            } else {
                              return RV32IM_INVALID;
                            }
                          } else {
                            return RV32IM_INVALID;
                          }
                        } else {
                          return RV32IM_INVALID;
                        }
                      } else {
                        return RV32IM_INVALID;
                      }
                    } else {
                      if ((instruction & (1 << 29)) == 0) {
                        if ((instruction & (1 << 28)) == 0) {
                          if ((instruction & (1 << 27)) == 0) {
                            if ((instruction & (1 << 26)) == 0) {
                              if ((instruction & (1 << 1)) == 0) {
                                return RV32IM_INVALID;
                              } else {
                                if ((instruction & (1 << 0)) == 0) {
                                  return RV32IM_INVALID;
                                } else {
                                  // 010000xxxxxxxxxxx101xxxxx0010011
                                  return RV32IM_SRAI;
                                }
                              }
                            } else {
                              return RV32IM_INVALID;
                            }
                          } else {
                            return RV32IM_INVALID;
                          }
                        } else {
                          return RV32IM_INVALID;
                        }
                      } else {
                        return RV32IM_INVALID;
                      }
                    }
                  } else {
                    return RV32IM_INVALID;
                  }
                }
              } else {
                if ((instruction & (1 << 12)) == 0) {
                  if ((instruction & (1 << 1)) == 0) {
                    return RV32IM_INVALID;
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IM_INVALID;
                    } else {
                      // xxxxxxxxxxxxxxxxx110xxxxx0010011
                      return RV32IM_ORI;
                    }
                  }
                } else {
                  if ((instruction & (1 << 1)) == 0) {
                    return RV32IM_INVALID;
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IM_INVALID;
                    } else {
                      // xxxxxxxxxxxxxxxxx111xxxxx0010011
                      return RV32IM_ANDI;
                    }
                  }
                }
              }
            }
          } else {
            if ((instruction & (1 << 1)) == 0) {
              return RV32IM_INVALID;
            } else {
              if ((instruction & (1 << 0)) == 0) {
                return RV32IM_INVALID;
              } else {
                // xxxxxxxxxxxxxxxxxxxxxxxxx0010111
                return RV32IM_AUIPC;
              }
            }
          }
        } else {
          return RV32IM_INVALID;
        }
      }
    } else {
      if ((instruction & (1 << 4)) == 0) {
        if ((instruction & (1 << 14)) == 0) {
          if ((instruction & (1 << 13)) == 0) {
            if ((instruction & (1 << 12)) == 0) {
              if ((instruction & (1 << 3)) == 0) {
                if ((instruction & (1 << 2)) == 0) {
                  if ((instruction & (1 << 1)) == 0) {
                    return RV32IM_INVALID;
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IM_INVALID;
                    } else {
                      // xxxxxxxxxxxxxxxxx000xxxxx0100011
                      return RV32IM_SB;
                    }
                  }
                } else {
                  return RV32IM_INVALID;
                }
              } else {
                return RV32IM_INVALID;
              }
            } else {
              if ((instruction & (1 << 3)) == 0) {
                if ((instruction & (1 << 2)) == 0) {
                  if ((instruction & (1 << 1)) == 0) {
                    return RV32IM_INVALID;
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IM_INVALID;
                    } else {
                      // xxxxxxxxxxxxxxxxx001xxxxx0100011
                      return RV32IM_SH;
                    }
                  }
                } else {
                  return RV32IM_INVALID;
                }
              } else {
                return RV32IM_INVALID;
              }
            }
          } else {
            if ((instruction & (1 << 12)) == 0) {
              if ((instruction & (1 << 3)) == 0) {
                if ((instruction & (1 << 2)) == 0) {
                  if ((instruction & (1 << 1)) == 0) {
                    return RV32IM_INVALID;
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IM_INVALID;
                    } else {
                      // xxxxxxxxxxxxxxxxx010xxxxx0100011
                      return RV32IM_SW;
                    }
                  }
                } else {
                  return RV32IM_INVALID;
                }
              } else {
                return RV32IM_INVALID;
              }
            } else {
              return RV32IM_INVALID;
            }
          }
        } else {
          return RV32IM_INVALID;
        }
      } else {
        if ((instruction & (1 << 3)) == 0) {
          if ((instruction & (1 << 2)) == 0) {
            if ((instruction & (1 << 31)) == 0) {
              if ((instruction & (1 << 30)) == 0) {
                if ((instruction & (1 << 29)) == 0) {
                  if ((instruction & (1 << 28)) == 0) {
                    if ((instruction & (1 << 27)) == 0) {
                      if ((instruction & (1 << 26)) == 0) {
                        if ((instruction & (1 << 25)) == 0) {
                          if ((instruction & (1 << 14)) == 0) {
                            if ((instruction & (1 << 13)) == 0) {
                              if ((instruction & (1 << 12)) == 0) {
                                if ((instruction & (1 << 1)) == 0) {
                                  return RV32IM_INVALID;
                                } else {
                                  if ((instruction & (1 << 0)) == 0) {
                                    return RV32IM_INVALID;
                                  } else {
                                    // 0000000xxxxxxxxxx000xxxxx0110011
                                    return RV32IM_ADD;
                                  }
                                }
                              } else {
                                if ((instruction & (1 << 1)) == 0) {
                                  return RV32IM_INVALID;
                                } else {
                                  if ((instruction & (1 << 0)) == 0) {
                                    return RV32IM_INVALID;
                                  } else {
                                    // 0000000xxxxxxxxxx001xxxxx0110011
                                    return RV32IM_SLL;
                                  }
                                }
                              }
                            } else {
                              if ((instruction & (1 << 12)) == 0) {
                                if ((instruction & (1 << 1)) == 0) {
                                  return RV32IM_INVALID;
                                } else {
                                  if ((instruction & (1 << 0)) == 0) {
                                    return RV32IM_INVALID;
                                  } else {
                                    // 0000000xxxxxxxxxx010xxxxx0110011
                                    return RV32IM_SLT;
                                  }
                                }
                              } else {
                                if ((instruction & (1 << 1)) == 0) {
                                  return RV32IM_INVALID;
                                } else {
                                  if ((instruction & (1 << 0)) == 0) {
                                    return RV32IM_INVALID;
                                  } else {
                                    // 0000000xxxxxxxxxx011xxxxx0110011
                                    return RV32IM_SLTU;
                                  }
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 13)) == 0) {
                              if ((instruction & (1 << 12)) == 0) {
                                if ((instruction & (1 << 1)) == 0) {
                                  return RV32IM_INVALID;
                                } else {
                                  if ((instruction & (1 << 0)) == 0) {
                                    return RV32IM_INVALID;
                                  } else {
                                    // 0000000xxxxxxxxxx100xxxxx0110011
                                    return RV32IM_XOR;
                                  }
                                }
                              } else {
                                if ((instruction & (1 << 1)) == 0) {
                                  return RV32IM_INVALID;
                                } else {
                                  if ((instruction & (1 << 0)) == 0) {
                                    return RV32IM_INVALID;
                                  } else {
                                    // 0000000xxxxxxxxxx101xxxxx0110011
                                    return RV32IM_SRL;
                                  }
                                }
                              }
                            } else {
                              if ((instruction & (1 << 12)) == 0) {
                                if ((instruction & (1 << 1)) == 0) {
                                  return RV32IM_INVALID;
                                } else {
                                  if ((instruction & (1 << 0)) == 0) {
                                    return RV32IM_INVALID;
                                  } else {
                                    // 0000000xxxxxxxxxx110xxxxx0110011
                                    return RV32IM_OR;
                                  }
                                }
                              } else {
                                if ((instruction & (1 << 1)) == 0) {
                                  return RV32IM_INVALID;
                                } else {
                                  if ((instruction & (1 << 0)) == 0) {
                                    return RV32IM_INVALID;
                                  } else {
                                    // 0000000xxxxxxxxxx111xxxxx0110011
                                    return RV32IM_AND;
                                  }
                                }
                              }
                            }
                          }
                        } else {
                          if ((instruction & (1 << 14)) == 0) {
                            if ((instruction & (1 << 13)) == 0) {
                              if ((instruction & (1 << 12)) == 0) {
                                if ((instruction & (1 << 1)) == 0) {
                                  return RV32IM_INVALID;
                                } else {
                                  if ((instruction & (1 << 0)) == 0) {
                                    return RV32IM_INVALID;
                                  } else {
                                    // 0000001xxxxxxxxxx000xxxxx0110011
                                    return RV32IM_MUL;
                                  }
                                }
                              } else {
                                if ((instruction & (1 << 1)) == 0) {
                                  return RV32IM_INVALID;
                                } else {
                                  if ((instruction & (1 << 0)) == 0) {
                                    return RV32IM_INVALID;
                                  } else {
                                    // 0000001xxxxxxxxxx001xxxxx0110011
                                    return RV32IM_MULH;
                                  }
                                }
                              }
                            } else {
                              if ((instruction & (1 << 12)) == 0) {
                                if ((instruction & (1 << 1)) == 0) {
                                  return RV32IM_INVALID;
                                } else {
                                  if ((instruction & (1 << 0)) == 0) {
                                    return RV32IM_INVALID;
                                  } else {
                                    // 0000001xxxxxxxxxx010xxxxx0110011
                                    return RV32IM_MULHSU;
                                  }
                                }
                              } else {
                                if ((instruction & (1 << 1)) == 0) {
                                  return RV32IM_INVALID;
                                } else {
                                  if ((instruction & (1 << 0)) == 0) {
                                    return RV32IM_INVALID;
                                  } else {
                                    // 0000001xxxxxxxxxx011xxxxx0110011
                                    return RV32IM_MULHU;
                                  }
                                }
                              }
                            }
                          } else {
                            if ((instruction & (1 << 13)) == 0) {
                              if ((instruction & (1 << 12)) == 0) {
                                if ((instruction & (1 << 1)) == 0) {
                                  return RV32IM_INVALID;
                                } else {
                                  if ((instruction & (1 << 0)) == 0) {
                                    return RV32IM_INVALID;
                                  } else {
                                    // 0000001xxxxxxxxxx100xxxxx0110011
                                    return RV32IM_DIV;
                                  }
                                }
                              } else {
                                if ((instruction & (1 << 1)) == 0) {
                                  return RV32IM_INVALID;
                                } else {
                                  if ((instruction & (1 << 0)) == 0) {
                                    return RV32IM_INVALID;
                                  } else {
                                    // 0000001xxxxxxxxxx101xxxxx0110011
                                    return RV32IM_DIVU;
                                  }
                                }
                              }
                            } else {
                              if ((instruction & (1 << 12)) == 0) {
                                if ((instruction & (1 << 1)) == 0) {
                                  return RV32IM_INVALID;
                                } else {
                                  if ((instruction & (1 << 0)) == 0) {
                                    return RV32IM_INVALID;
                                  } else {
                                    // 0000001xxxxxxxxxx110xxxxx0110011
                                    return RV32IM_REM;
                                  }
                                }
                              } else {
                                if ((instruction & (1 << 1)) == 0) {
                                  return RV32IM_INVALID;
                                } else {
                                  if ((instruction & (1 << 0)) == 0) {
                                    return RV32IM_INVALID;
                                  } else {
                                    // 0000001xxxxxxxxxx111xxxxx0110011
                                    return RV32IM_REMU;
                                  }
                                }
                              }
                            }
                          }
                        }
                      } else {
                        return RV32IM_INVALID;
                      }
                    } else {
                      return RV32IM_INVALID;
                    }
                  } else {
                    return RV32IM_INVALID;
                  }
                } else {
                  return RV32IM_INVALID;
                }
              } else {
                if ((instruction & (1 << 29)) == 0) {
                  if ((instruction & (1 << 28)) == 0) {
                    if ((instruction & (1 << 27)) == 0) {
                      if ((instruction & (1 << 26)) == 0) {
                        if ((instruction & (1 << 25)) == 0) {
                          if ((instruction & (1 << 14)) == 0) {
                            if ((instruction & (1 << 13)) == 0) {
                              if ((instruction & (1 << 12)) == 0) {
                                if ((instruction & (1 << 1)) == 0) {
                                  return RV32IM_INVALID;
                                } else {
                                  if ((instruction & (1 << 0)) == 0) {
                                    return RV32IM_INVALID;
                                  } else {
                                    // 0100000xxxxxxxxxx000xxxxx0110011
                                    return RV32IM_SUB;
                                  }
                                }
                              } else {
                                return RV32IM_INVALID;
                              }
                            } else {
                              return RV32IM_INVALID;
                            }
                          } else {
                            if ((instruction & (1 << 13)) == 0) {
                              if ((instruction & (1 << 12)) == 0) {
                                return RV32IM_INVALID;
                              } else {
                                if ((instruction & (1 << 1)) == 0) {
                                  return RV32IM_INVALID;
                                } else {
                                  if ((instruction & (1 << 0)) == 0) {
                                    return RV32IM_INVALID;
                                  } else {
                                    // 0100000xxxxxxxxxx101xxxxx0110011
                                    return RV32IM_SRA;
                                  }
                                }
                              }
                            } else {
                              return RV32IM_INVALID;
                            }
                          }
                        } else {
                          return RV32IM_INVALID;
                        }
                      } else {
                        return RV32IM_INVALID;
                      }
                    } else {
                      return RV32IM_INVALID;
                    }
                  } else {
                    return RV32IM_INVALID;
                  }
                } else {
                  return RV32IM_INVALID;
                }
              }
            } else {
              return RV32IM_INVALID;
            }
          } else {
            if ((instruction & (1 << 1)) == 0) {
              return RV32IM_INVALID;
            } else {
              if ((instruction & (1 << 0)) == 0) {
                return RV32IM_INVALID;
              } else {
                // xxxxxxxxxxxxxxxxxxxxxxxxx0110111
                return RV32IM_LUI;
              }
            }
          }
        } else {
          return RV32IM_INVALID;
        }
      }
    }
  } else {
    if ((instruction & (1 << 5)) == 0) {
      return RV32IM_INVALID;
    } else {
      if ((instruction & (1 << 4)) == 0) {
        if ((instruction & (1 << 3)) == 0) {
          if ((instruction & (1 << 14)) == 0) {
            if ((instruction & (1 << 13)) == 0) {
              if ((instruction & (1 << 12)) == 0) {
                if ((instruction & (1 << 2)) == 0) {
                  if ((instruction & (1 << 1)) == 0) {
                    return RV32IM_INVALID;
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IM_INVALID;
                    } else {
                      // xxxxxxxxxxxxxxxxx000xxxxx1100011
                      return RV32IM_BEQ;
                    }
                  }
                } else {
                  if ((instruction & (1 << 1)) == 0) {
                    return RV32IM_INVALID;
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IM_INVALID;
                    } else {
                      // xxxxxxxxxxxxxxxxx000xxxxx1100111
                      return RV32IM_JALR;
                    }
                  }
                }
              } else {
                if ((instruction & (1 << 2)) == 0) {
                  if ((instruction & (1 << 1)) == 0) {
                    return RV32IM_INVALID;
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IM_INVALID;
                    } else {
                      // xxxxxxxxxxxxxxxxx001xxxxx1100011
                      return RV32IM_BNE;
                    }
                  }
                } else {
                  return RV32IM_INVALID;
                }
              }
            } else {
              return RV32IM_INVALID;
            }
          } else {
            if ((instruction & (1 << 13)) == 0) {
              if ((instruction & (1 << 12)) == 0) {
                if ((instruction & (1 << 2)) == 0) {
                  if ((instruction & (1 << 1)) == 0) {
                    return RV32IM_INVALID;
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IM_INVALID;
                    } else {
                      // xxxxxxxxxxxxxxxxx100xxxxx1100011
                      return RV32IM_BLT;
                    }
                  }
                } else {
                  return RV32IM_INVALID;
                }
              } else {
                if ((instruction & (1 << 2)) == 0) {
                  if ((instruction & (1 << 1)) == 0) {
                    return RV32IM_INVALID;
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IM_INVALID;
                    } else {
                      // xxxxxxxxxxxxxxxxx101xxxxx1100011
                      return RV32IM_BGE;
                    }
                  }
                } else {
                  return RV32IM_INVALID;
                }
              }
            } else {
              if ((instruction & (1 << 12)) == 0) {
                if ((instruction & (1 << 2)) == 0) {
                  if ((instruction & (1 << 1)) == 0) {
                    return RV32IM_INVALID;
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IM_INVALID;
                    } else {
                      // xxxxxxxxxxxxxxxxx110xxxxx1100011
                      return RV32IM_BLTU;
                    }
                  }
                } else {
                  return RV32IM_INVALID;
                }
              } else {
                if ((instruction & (1 << 2)) == 0) {
                  if ((instruction & (1 << 1)) == 0) {
                    return RV32IM_INVALID;
                  } else {
                    if ((instruction & (1 << 0)) == 0) {
                      return RV32IM_INVALID;
                    } else {
                      // xxxxxxxxxxxxxxxxx111xxxxx1100011
                      return RV32IM_BGEU;
                    }
                  }
                } else {
                  return RV32IM_INVALID;
                }
              }
            }
          }
        } else {
          if ((instruction & (1 << 2)) == 0) {
            return RV32IM_INVALID;
          } else {
            if ((instruction & (1 << 1)) == 0) {
              return RV32IM_INVALID;
            } else {
              if ((instruction & (1 << 0)) == 0) {
                return RV32IM_INVALID;
              } else {
                // xxxxxxxxxxxxxxxxxxxxxxxxx1101111
                return RV32IM_JAL;
              }
            }
          }
        }
      } else {
        if ((instruction & (1 << 31)) == 0) {
          if ((instruction & (1 << 30)) == 0) {
            if ((instruction & (1 << 29)) == 0) {
              if ((instruction & (1 << 28)) == 0) {
                if ((instruction & (1 << 27)) == 0) {
                  if ((instruction & (1 << 26)) == 0) {
                    if ((instruction & (1 << 25)) == 0) {
                      if ((instruction & (1 << 24)) == 0) {
                        if ((instruction & (1 << 23)) == 0) {
                          if ((instruction & (1 << 22)) == 0) {
                            if ((instruction & (1 << 21)) == 0) {
                              if ((instruction & (1 << 20)) == 0) {
                                if ((instruction & (1 << 19)) == 0) {
                                  if ((instruction & (1 << 18)) == 0) {
                                    if ((instruction & (1 << 17)) == 0) {
                                      if ((instruction & (1 << 16)) == 0) {
                                        if ((instruction & (1 << 15)) == 0) {
                                          if ((instruction & (1 << 14)) == 0) {
                                            if ((instruction & (1 << 13)) == 0) {
                                              if ((instruction & (1 << 12)) == 0) {
                                                if ((instruction & (1 << 11)) == 0) {
                                                  if ((instruction & (1 << 10)) == 0) {
                                                    if ((instruction & (1 << 9)) == 0) {
                                                      if ((instruction & (1 << 8)) == 0) {
                                                        if ((instruction & (1 << 7)) == 0) {
                                                          if ((instruction & (1 << 3)) == 0) {
                                                            if ((instruction & (1 << 2)) == 0) {
                                                              if ((instruction & (1 << 1)) == 0) {
                                                                return RV32IM_INVALID;
                                                              } else {
                                                                if ((instruction & (1 << 0)) == 0) {
                                                                  return RV32IM_INVALID;
                                                                } else {
                                                                  // 00000000000000000000000001110011
                                                                  return RV32IM_ECALL;
                                                                }
                                                              }
                                                            } else {
                                                              return RV32IM_INVALID;
                                                            }
                                                          } else {
                                                            return RV32IM_INVALID;
                                                          }
                                                        } else {
                                                          return RV32IM_INVALID;
                                                        }
                                                      } else {
                                                        return RV32IM_INVALID;
                                                      }
                                                    } else {
                                                      return RV32IM_INVALID;
                                                    }
                                                  } else {
                                                    return RV32IM_INVALID;
                                                  }
                                                } else {
                                                  return RV32IM_INVALID;
                                                }
                                              } else {
                                                return RV32IM_INVALID;
                                              }
                                            } else {
                                              return RV32IM_INVALID;
                                            }
                                          } else {
                                            return RV32IM_INVALID;
                                          }
                                        } else {
                                          return RV32IM_INVALID;
                                        }
                                      } else {
                                        return RV32IM_INVALID;
                                      }
                                    } else {
                                      return RV32IM_INVALID;
                                    }
                                  } else {
                                    return RV32IM_INVALID;
                                  }
                                } else {
                                  return RV32IM_INVALID;
                                }
                              } else {
                                if ((instruction & (1 << 19)) == 0) {
                                  if ((instruction & (1 << 18)) == 0) {
                                    if ((instruction & (1 << 17)) == 0) {
                                      if ((instruction & (1 << 16)) == 0) {
                                        if ((instruction & (1 << 15)) == 0) {
                                          if ((instruction & (1 << 14)) == 0) {
                                            if ((instruction & (1 << 13)) == 0) {
                                              if ((instruction & (1 << 12)) == 0) {
                                                if ((instruction & (1 << 11)) == 0) {
                                                  if ((instruction & (1 << 10)) == 0) {
                                                    if ((instruction & (1 << 9)) == 0) {
                                                      if ((instruction & (1 << 8)) == 0) {
                                                        if ((instruction & (1 << 7)) == 0) {
                                                          if ((instruction & (1 << 3)) == 0) {
                                                            if ((instruction & (1 << 2)) == 0) {
                                                              if ((instruction & (1 << 1)) == 0) {
                                                                return RV32IM_INVALID;
                                                              } else {
                                                                if ((instruction & (1 << 0)) == 0) {
                                                                  return RV32IM_INVALID;
                                                                } else {
                                                                  // 00000000000100000000000001110011
                                                                  return RV32IM_EBREAK;
                                                                }
                                                              }
                                                            } else {
                                                              return RV32IM_INVALID;
                                                            }
                                                          } else {
                                                            return RV32IM_INVALID;
                                                          }
                                                        } else {
                                                          return RV32IM_INVALID;
                                                        }
                                                      } else {
                                                        return RV32IM_INVALID;
                                                      }
                                                    } else {
                                                      return RV32IM_INVALID;
                                                    }
                                                  } else {
                                                    return RV32IM_INVALID;
                                                  }
                                                } else {
                                                  return RV32IM_INVALID;
                                                }
                                              } else {
                                                return RV32IM_INVALID;
                                              }
                                            } else {
                                              return RV32IM_INVALID;
                                            }
                                          } else {
                                            return RV32IM_INVALID;
                                          }
                                        } else {
                                          return RV32IM_INVALID;
                                        }
                                      } else {
                                        return RV32IM_INVALID;
                                      }
                                    } else {
                                      return RV32IM_INVALID;
                                    }
                                  } else {
                                    return RV32IM_INVALID;
                                  }
                                } else {
                                  return RV32IM_INVALID;
                                }
                              }
                            } else {
                              return RV32IM_INVALID;
                            }
                          } else {
                            return RV32IM_INVALID;
                          }
                        } else {
                          return RV32IM_INVALID;
                        }
                      } else {
                        return RV32IM_INVALID;
                      }
                    } else {
                      return RV32IM_INVALID;
                    }
                  } else {
                    return RV32IM_INVALID;
                  }
                } else {
                  return RV32IM_INVALID;
                }
              } else {
                return RV32IM_INVALID;
              }
            } else {
              return RV32IM_INVALID;
            }
          } else {
            return RV32IM_INVALID;
          }
        } else {
          return RV32IM_INVALID;
        }
      }
    }
  }
}
