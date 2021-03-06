#include <string.h>
#include <stdio.h>
#include "forcecrc32.h"

unsigned char ida_chars[] =
{
  0xD3, 0x5F, 0x78, 0x9B, 0x11, 0x2C, 0x66, 0x89, 0x53, 0x20,
  0xC6, 0x18, 0x43, 0xBF, 0xB9, 0xFF, 0x91, 0x00, 0x47, 0xA4,
  0xE8, 0x00, 0x7D, 0xEB, 0x3D, 0xC3, 0xC5, 0x13, 0x12, 0xA2,
  0x89, 0x9A, 0x30, 0x22, 0xD0, 0xD1, 0x4E, 0xF6, 0x59, 0x73,
  0xB2, 0xDF, 0xA7, 0xBB, 0x9B, 0x0A, 0x56, 0xAF, 0x9F, 0x6D,
  0xBD, 0xA9, 0x37, 0xD7, 0x38, 0x3E, 0x2F, 0xDD, 0x03, 0xC1,
  0xCE, 0x95, 0x33, 0xD3, 0x65, 0xB9, 0x9F, 0x15, 0xE1, 0xDB,
  0x14, 0x4B, 0x6F, 0xD2, 0x32, 0x44, 0x6A, 0xA1, 0x5C, 0xA0,
  0x95, 0x16, 0x2D, 0x11, 0xE9, 0x6E, 0x06, 0x04, 0x4C, 0x62,
  0xAE, 0x22, 0x60, 0x1B, 0xBF, 0x64, 0x93, 0xF9, 0x4B, 0x0A,
  0x03, 0x75, 0xEC, 0xE8, 0x40, 0x66, 0x93, 0x76, 0xFA, 0x4E,
  0x61, 0xD5, 0xAD, 0xA2, 0x6F, 0xE6, 0x90, 0x82, 0x76, 0x20,
  0xC5, 0x52, 0x2D, 0x05, 0xD1, 0xF3, 0xAB, 0xE9, 0x1E, 0xC0,
  0xFD, 0x5A, 0x5A, 0x99, 0x8A, 0x94, 0xDB, 0x5A, 0x73, 0xD0,
  0x30, 0x52, 0xE5, 0x1E, 0xC1, 0x0C, 0xE1, 0xAA, 0x8D, 0xD8,
  0xB0, 0x78, 0x75, 0xE5, 0x87, 0xEB, 0x8F, 0x2E, 0x09, 0xC3,
  0x98, 0xFF, 0xE0, 0x80, 0xC5, 0xFF, 0xDA, 0x0A, 0x10, 0x49,
  0xE3, 0x94, 0x78, 0xA7, 0xA9, 0x12, 0x17, 0x80, 0x7B, 0x71,
  0xFF, 0x60, 0xD9, 0x05, 0x74, 0xDE, 0x24, 0xB2, 0xAF, 0x94,
  0xBE, 0x63, 0x23, 0xF7, 0x79, 0xE4, 0x0C, 0x08, 0xD5, 0x3A,
  0x89, 0x9F, 0xCC, 0x28, 0xFC, 0x50, 0x3A, 0x69, 0xC8, 0x71,
  0xB9, 0xEB, 0xCE, 0xAE, 0x8E, 0xF6, 0xE6, 0x7B, 0x7A, 0xF4,
  0xFF, 0x32, 0xE6, 0x01, 0x86, 0xD3, 0x74, 0xF9, 0x59, 0x4A,
  0x84, 0xD5, 0xFD, 0x5C, 0x16, 0xE4, 0xCF, 0xB2, 0xB4, 0x82,
  0x87, 0x12, 0xAF, 0x74, 0x5D, 0x5F, 0x08, 0xF7, 0xFF, 0x36,
  0xBF, 0x79, 0x89, 0xD8, 0xEA, 0x72, 0xEC, 0x73, 0x16, 0x19,
  0x6B, 0x0F, 0x6B, 0x26, 0x24, 0xA4, 0x0B, 0x0C, 0xAA, 0x3B,
  0x5E, 0x61, 0xD8, 0xA2, 0x01, 0x73, 0x1D, 0x3A, 0x23, 0x19,
  0xD0, 0x45, 0x6E, 0x9D, 0x7E, 0x83, 0x1D, 0x33, 0x72, 0x14,
  0xBE, 0x2E, 0xE8, 0x77, 0x01, 0xCC, 0x1D, 0x40, 0x11, 0xAE,
  0x84, 0x6A, 0xD5, 0xFA, 0xDE, 0x11, 0x54, 0x70, 0x86, 0xFB,
  0x9C, 0xAE, 0x86, 0x49, 0x3D, 0xAB, 0xFA, 0x96, 0xE7, 0x0A,
  0x48, 0x1C, 0xB2, 0xEE, 0x4E, 0xF5, 0x83, 0xFD, 0x8A, 0xE6,
  0x7D, 0x6A, 0x32, 0xF5, 0x9D, 0x99, 0xC6, 0x77, 0x26, 0x92,
  0xA9, 0x87, 0x65, 0x9F, 0xE1, 0x66, 0xDC, 0x87, 0x72, 0x1F,
  0x33, 0xA0, 0x51, 0x00, 0x66, 0x64, 0xDF, 0xE3, 0xE1, 0x3A,
  0x50, 0xCB, 0xA5, 0x32, 0x12, 0xC6, 0xFC, 0x07, 0x9A, 0xA5,
  0x88, 0x85, 0x37, 0xDD, 0x08, 0x2E, 0x7E, 0x6A, 0xFC, 0xD0,
  0x44, 0x15, 0xA6, 0x83, 0xBE, 0x44, 0xEE, 0xAE, 0xFD, 0x5B,
  0xB7, 0x06, 0x6E, 0x44, 0x15, 0xAD, 0x59, 0x96, 0xBA, 0x5D,
  0xDB, 0xCA, 0xA3, 0xC9, 0x2C, 0xBC, 0xF7, 0x8D, 0x48, 0xB9,
  0x47, 0x1B, 0xAE, 0x98, 0xE8, 0xF3, 0x5A, 0xA2, 0x76, 0xCA,
  0x60, 0x51, 0x05, 0x21, 0xC7, 0x44, 0xD3, 0xF7, 0x51, 0x7E,
  0xD2, 0xC6, 0x04, 0x49, 0xAE, 0xAD, 0xB1, 0x3E, 0x81, 0x71,
  0x9C, 0x9F, 0xDC, 0x0B, 0x84, 0x3A, 0x90, 0x30, 0x90, 0xE8,
  0x27, 0x77, 0xB6, 0x12, 0xCE, 0x28, 0xED, 0x3A, 0x4D, 0xA1,
  0x3E, 0x89, 0xD3, 0x73, 0x1D, 0xE5, 0x26, 0xBD, 0xFC, 0xBC,
  0x0E, 0x71, 0x89, 0x7F, 0x79, 0xC2, 0x33, 0x3B, 0xC8, 0x9F,
  0xAD, 0xF9, 0xE2, 0xF8, 0xA1, 0xC9, 0x41, 0x3A, 0xFF, 0x4C,
  0x60, 0xBB, 0x68, 0xAE, 0x22, 0x8C, 0x67, 0xBA, 0xE1, 0xB6,
  0x7B, 0xDC, 0x22, 0xCD, 0x04, 0x7E, 0x17, 0x34, 0x3F, 0xBB,
  0xD7, 0xB3, 0xF4, 0x4C, 0x33, 0x32, 0x0C, 0x89, 0x0A, 0xB7,
  0x37, 0x10, 0xC1, 0x64, 0x89, 0x54, 0x69, 0xB8, 0x3D, 0x9A,
  0xA0, 0x94, 0x9A, 0x81, 0xC7, 0x7A, 0xF9, 0xAA, 0x0F, 0x1C,
  0x5B, 0x2E, 0x37, 0xF0, 0x7D, 0x84, 0xC7, 0x00, 0x59, 0x9E,
  0x50, 0xC1, 0x37, 0x41, 0xDB, 0xED, 0xC6, 0x8B, 0x9F, 0x12,
  0x37, 0xE2, 0x00, 0x8C, 0xEE, 0x73, 0x49, 0x63, 0x13, 0x3A,
  0xEB, 0x86, 0x06, 0x46, 0x2A, 0xF8, 0xC1, 0x10, 0xEB, 0xB8,
  0x9B, 0x60, 0xE6, 0xEA, 0x5E, 0x0F, 0x95, 0x4C, 0x97, 0xE8,
  0xB4, 0x58, 0xC7, 0x1C, 0xFF, 0xE3, 0xDC, 0xA6, 0x3A, 0xC3,
  0xA5, 0xC0, 0x73, 0x1C, 0xA5, 0x0C, 0x08, 0xA6, 0x45, 0x4A,
  0x36, 0x3E, 0x7E, 0x14, 0x73, 0x2B, 0xE9, 0x10, 0x5E, 0x29,
  0xC2, 0x53, 0x8B, 0x32, 0x15, 0xD7, 0xDC, 0x71, 0x5D, 0xB1,
  0x67, 0x12, 0xBD, 0xAD, 0xC3, 0x91, 0x68, 0x0A, 0x2F, 0xB1,
  0xF2, 0x2F, 0xE5, 0xC0, 0x48, 0x1E, 0xDC, 0xE4, 0x11, 0x15,
  0x45, 0x0D, 0x2F, 0x8E, 0x8A, 0x7F, 0x29, 0xF1, 0x6A, 0xAA,
  0x5C, 0x52, 0xBA, 0xA7, 0xE1, 0x1F, 0x34, 0x53, 0xD7, 0xBB,
  0xC5, 0x7E, 0x80, 0x48, 0x5C, 0xD3, 0x03, 0x4D, 0x94, 0x41,
  0x16, 0xA9, 0xAE, 0x8F, 0x2F, 0x05, 0x90, 0x0D, 0xD2, 0xC9,
  0xD1, 0xCF, 0x23, 0xCB, 0x83, 0x22, 0x26, 0x9A, 0xF8, 0x33,
  0x91, 0xFD, 0xC7, 0x22, 0x58, 0xD2, 0xA8, 0x82, 0x0A, 0x62,
  0x58, 0xB4, 0xD3, 0x14, 0xAD, 0x23, 0x42, 0xF0, 0x27, 0x39,
  0x7E, 0x0C, 0x1D, 0xCC, 0x28, 0xC7, 0x18, 0x79, 0xE6, 0xEB,
  0x11, 0x6C, 0xCF, 0x73, 0x32, 0x87, 0x0B, 0xF7, 0x73, 0x75,
  0xAA, 0xD0, 0x82, 0xC7, 0xBB, 0x70, 0x89, 0xB7, 0xEB, 0x79,
  0x53, 0xA3, 0x49, 0x0A, 0x4D, 0x42, 0x16, 0xA8, 0x47, 0xFC,
  0x1C, 0x36, 0x5C, 0x36, 0x77, 0x84, 0x32, 0x3F, 0xE2, 0x08,
  0xC6, 0x73, 0x17, 0x65, 0xBC, 0x3C, 0xBC, 0x52, 0x85, 0x9F,
  0x2E, 0x50, 0xAE, 0x15, 0x9B, 0xC4, 0x60, 0x33, 0xD7, 0xD0,
  0xAB, 0x07, 0x37, 0x88, 0xC0, 0xEC, 0x56, 0x4D, 0xD3, 0x24,
  0x7F, 0x85, 0xD5, 0x86, 0xF6, 0x71, 0xA2, 0xB5, 0x21, 0x22,
  0xFB, 0x51, 0x26, 0xBF, 0x53, 0xEE, 0x61, 0xA1, 0xB6, 0x94,
  0x82, 0xDA, 0x1D, 0x91, 0xE3, 0x6D, 0x1C, 0xD2, 0x88, 0xBE,
  0xC4, 0x27, 0xD5, 0x0F, 0x8B, 0x31, 0x39, 0xDE, 0x60, 0xFF,
  0x5A, 0xE0, 0xD3, 0x33, 0x3F, 0xD0, 0x96, 0x6D, 0x82, 0x8E,
  0x17, 0xCA, 0x37, 0x98, 0x71, 0x1D, 0x72, 0x88, 0x45, 0x68,
  0x72, 0x2D, 0x54, 0x82, 0x5A, 0xBC, 0x67, 0x6F, 0x44, 0x82,
  0x35, 0x17, 0xC4, 0xA5, 0x99, 0x22, 0x77, 0xEF, 0x2E, 0xB0,
  0x5A, 0x93, 0x3A, 0x0D, 0xF4, 0xEB, 0x85, 0xD9, 0x5A, 0xC0,
  0x51, 0xE4, 0x9F, 0x6F, 0x97, 0x50, 0xEC, 0x38, 0x3C, 0xFA,
  0x07, 0x91, 0x3D, 0x06, 0x2F, 0x3A, 0xBB, 0xC7, 0x59, 0x91,
  0x10, 0xFA, 0x1E, 0x12, 0x19, 0x28, 0x3D, 0x2E, 0x29, 0x7B,
  0xF5, 0x1B, 0x52, 0x3E, 0x8A, 0x78, 0x49, 0xA8, 0x19, 0xE6,
  0xDF, 0x58, 0xAC, 0x3C, 0xB9, 0x4F, 0x4A, 0x40, 0x1B, 0xDC,
  0xDB, 0x76, 0x9D, 0x83, 0x07, 0xE0, 0x21, 0x56, 0xFC, 0x9E,
  0xB7, 0x6A, 0x13, 0x04, 0xD8, 0xA6, 0x81, 0xD4, 0xDE, 0x79,
  0xDD, 0xD0, 0x54, 0x54, 0x93, 0xB1, 0x8A, 0xD0, 0x34, 0x0D,
  0xED, 0x8C, 0x0B, 0xCE, 0x5D, 0xBA, 0x63, 0x2B, 0xE6, 0xF5,
  0x9D, 0x33, 0xA5, 0x8D, 0x5C, 0x9B, 0xC0, 0xAE, 0x99, 0x54,
  0xED, 0x88, 0x6C, 0x44, 0x0A, 0xDD, 0xD0, 0x8C, 0xE4, 0x48,
  0x68, 0xC1, 0x54, 0xA6, 0x72, 0x13, 0x66, 0x42, 0x40, 0x51,
  0xFD, 0xDA, 0xFB, 0xA1, 0xBE, 0x3E, 0xAF, 0xAB, 0x15, 0x61,
  0xFC, 0x77, 0x7C, 0xA7, 0x6B, 0x40, 0x87, 0x80, 0x38, 0xFE,
  0xDF, 0x49, 0x18, 0xE9, 0x09, 0xB8, 0x12, 0x96, 0xBD, 0x1D,
  0xC5, 0xFA, 0xBF, 0x31, 0x97, 0xE7, 0x1D, 0x16, 0xF2, 0x98,
  0x63, 0xD0, 0xD5, 0x6D, 0x52, 0xF1, 0x8F, 0xDA, 0x3E, 0x5C,
  0x41, 0xEB, 0x0A, 0x84, 0xFB, 0x7D, 0xCD, 0xDE, 0x81, 0x82,
  0xF5, 0x16, 0x3D, 0x7F, 0x1F, 0x35, 0x8F, 0xC2, 0xB8, 0x4B,
  0xE7, 0xC3, 0x1F, 0x3F, 0xA1, 0xEE, 0xFD, 0xED, 0x34, 0x73,
  0xCE, 0xC8, 0xE0, 0xC9, 0xDE, 0xF4, 0x80, 0x71, 0xF1, 0x55,
  0x6D, 0x13, 0x49, 0x81, 0x51, 0x6D, 0x32, 0x66, 0x53, 0x13,
  0x1C, 0x62, 0xE7, 0x7F, 0xA0, 0x43, 0x55, 0xF2, 0x2B, 0x5D,
  0xEA, 0x3E, 0x8D, 0xB5, 0xFE, 0x20, 0x99, 0x71, 0x0E, 0xDB,
  0xAD, 0x62, 0xA9, 0xD4, 0x3A, 0x5C, 0xCA, 0xD5, 0x2A, 0x59,
  0x28, 0x02, 0x3A, 0x75, 0x1D, 0x30, 0x3C, 0x20, 0x7C, 0xBA,
  0x1F, 0xA8, 0x91, 0x22, 0x56, 0x36, 0x19, 0xD4, 0x37, 0x79,
  0x07, 0x4A, 0x29, 0x57, 0x06, 0xFE, 0xB0, 0x91, 0xD9, 0x42,
  0x2A, 0x56, 0xFD, 0x46, 0x3E, 0xC2, 0xD8, 0xCA, 0x92, 0xFE,
  0xA3, 0x4F, 0x57, 0x5D, 0x32, 0xD2, 0xA1, 0xAF, 0xBE, 0x6C,
  0x1C, 0x15, 0x46, 0x9E, 0x82, 0xC6, 0x43, 0x60, 0xC1, 0xA5,
  0x98, 0x06, 0xC4, 0x24, 0xB4, 0x48, 0x8A, 0x8D, 0x43, 0x25,
  0x2E, 0x14, 0xAF, 0xC1, 0xB0, 0xDC, 0xB0, 0x00, 0x06, 0x7C,
  0xC7, 0xA5, 0xC9, 0x37, 0x4B, 0x88, 0x81, 0xBC, 0xE3, 0xE7,
  0xD6, 0x07, 0x52, 0x85, 0x0D, 0x51, 0x7E, 0x82, 0xAF, 0x72,
  0x9B, 0x61, 0x45, 0xAD, 0x83, 0xCF, 0x92, 0x85, 0xB7, 0x78,
  0xEA, 0xBD, 0x0D, 0x27, 0xAB, 0x62, 0xCB, 0xE7, 0x2C, 0x50,
  0xF3, 0x15, 0x39, 0xFB, 0x41, 0x37, 0xFA, 0x79, 0x06, 0x55,
  0xD1, 0x3D, 0x12, 0x20, 0x2F, 0x1B, 0xC3, 0x3C, 0x65, 0x17,
  0xFF, 0xFE, 0x0D, 0xFE, 0xC3, 0x70, 0xB5, 0xD4, 0x66, 0xE6,
  0xA8, 0x5F, 0x48, 0xA3, 0x3F, 0x25, 0xFB, 0x51, 0xC6, 0xDA,
  0x93, 0x85, 0xFD, 0xBB, 0x0D, 0x87, 0x3A, 0xC6, 0xE8, 0xC9,
  0x9E, 0x60, 0x5A, 0x18, 0x34, 0x9F, 0x18, 0xCC, 0x1C, 0x0F,
  0x2F, 0xAB, 0x3E, 0x9D, 0x51, 0x21, 0x87, 0x26, 0xFD, 0xFB,
  0x56, 0xA8, 0xCF, 0xB0, 0x4D, 0xCE, 0x29, 0xF3, 0x27, 0x3C,
  0x85, 0xF3, 0x4E, 0x62, 0x5D, 0x1A, 0xD4, 0xB9, 0xEE, 0xF6,
  0x0F, 0x3F, 0x8A, 0x95, 0xF8, 0xA1, 0x47, 0xE2, 0x91, 0xC7,
  0xE5, 0x2B, 0x4A, 0x74, 0x63, 0xB4, 0x56, 0x61, 0x5D, 0x2B,
  0x0E, 0xB8, 0xC5, 0xB1, 0xCF, 0x10, 0x06, 0xAD, 0x70, 0xC3,
  0xEC, 0xB3, 0x25, 0x42, 0xBA, 0x84, 0xBD, 0x8F, 0xEF, 0x7E,
  0xDE, 0xB7, 0x63, 0xA7, 0x23, 0xFF, 0x15, 0xA7, 0x82, 0x1F,
  0x20, 0xDE, 0x3B, 0xB1, 0xDF, 0x65, 0x05, 0xBA, 0xA2, 0xE3,
  0x65, 0x6D, 0xD1, 0xE0, 0xF6, 0x72, 0xF1, 0x49, 0xE8, 0xC9,
  0x29, 0xB5, 0x11, 0xA8, 0x78, 0x6C, 0xB5, 0xAD, 0xB8, 0xE6,
  0xC3, 0x3F, 0x46, 0x5C, 0xDF, 0x89, 0xEC, 0x19, 0xAC, 0x51,
  0xE9, 0x8A, 0x23, 0xDC, 0xF0, 0xEF, 0x89, 0x96, 0x29, 0x21,
  0x13, 0x4A, 0x20, 0xC9, 0x5C, 0x15, 0xD9, 0x4F, 0x71, 0xE2,
  0x06, 0x39, 0xDC, 0x31, 0xFE, 0x28, 0x7E, 0x1E, 0x27, 0x15,
  0x60, 0x8A, 0x11, 0x9B, 0xAD, 0x37, 0xA2, 0x7E, 0x14, 0x1C,
  0xFB, 0x53, 0x4B, 0x92, 0x69, 0xFB, 0xCA, 0xCF, 0x0B, 0x37,
  0x5F, 0x01, 0x49, 0xC2, 0x1B, 0x13, 0xAC, 0x34, 0x56, 0x74,
  0xE8, 0xDA, 0xA1, 0x64, 0x6C, 0xD0, 0x8F, 0x00, 0x1E, 0x34,
  0xF8, 0x3D, 0x0F, 0xB0, 0xEE, 0x6B, 0xD7, 0x31, 0x37, 0x46,
  0xBA, 0x22, 0xA6, 0x63, 0xF3, 0x01, 0x4D, 0x3D, 0x07, 0x9D,
  0xD5, 0x1F, 0xA8, 0x57, 0x85, 0x08, 0x7E, 0xEF, 0xB0, 0x0B,
  0x3C, 0x91, 0x2F, 0x90, 0x28, 0xAC, 0xC8, 0x68, 0x85, 0x5E,
  0xD8, 0x57, 0x0E, 0x78, 0xAA, 0x1C, 0x39, 0x94, 0x5E, 0x10,
  0x23, 0x72, 0xBF, 0x14, 0xF9, 0x33, 0xB4, 0xDC, 0x2B, 0x65,
  0xF6, 0x94, 0x51, 0x5A, 0xFC, 0x07, 0xA2, 0xE9, 0xFC, 0x96,
  0x70, 0x8F, 0xCD, 0x8C, 0xC3, 0xAD, 0xB8, 0xB6, 0x09, 0x69,
  0xB5, 0xC1, 0xC3, 0xE8, 0x24, 0xD2, 0xB4, 0x44, 0xE4, 0x01,
  0x97, 0x3C, 0xE8, 0x6A, 0x65, 0x76, 0xFF, 0x4C, 0x16, 0x51,
  0xB4, 0x72, 0xEB, 0x85, 0x20, 0x9B, 0x99, 0xE3, 0x30, 0x7B,
  0xB3, 0x5C, 0x15, 0x4E, 0xFF, 0x36, 0x83, 0x31, 0xF4, 0xE5,
  0x8F, 0x15, 0xA8, 0x3D, 0x5A, 0x2F, 0x78, 0x37, 0x5A, 0x31,
  0xD1, 0x9F, 0xF1, 0x95, 0xF0, 0xF9, 0x48, 0x9E, 0x79, 0xD8,
  0x15, 0x16, 0x12, 0xCF, 0x34, 0x52, 0xF8, 0xAD, 0x28, 0x56,
  0xF7, 0x84, 0xBB, 0x04, 0xA4, 0xBC, 0x70, 0xD7, 0x30, 0x27,
  0x2B, 0x94, 0xD6, 0x79, 0x30, 0x1A, 0xC9, 0x15, 0xC3, 0x34,
  0xDD, 0x20, 0x43, 0x5B, 0xD8, 0xB8, 0xD9, 0x31, 0x5A, 0x6E,
  0x06, 0x9B, 0x71, 0xB6, 0xD0, 0xC0, 0x4C, 0xC1, 0x40, 0x8C,
  0x65, 0x00, 0xF8, 0x5F, 0x32, 0xF7, 0xE0, 0xE4, 0x7C, 0x2A,
  0xED, 0x79, 0xE5, 0xAE, 0xB0, 0x6B, 0x64, 0xFD, 0xF1, 0xE3,
  0x0E, 0x13, 0xEA, 0xC6, 0xB1, 0x37, 0x9D, 0x10, 0xBE, 0x3F,
  0xDE, 0x9E, 0xD8, 0xAC, 0xF4, 0x77, 0x2C, 0xAD, 0x37, 0x27,
  0xDD, 0xD2, 0xEF, 0xD6, 0x05, 0x65, 0xEF, 0x1D, 0x9D, 0xBF,
  0x24, 0xE0, 0x74, 0x76, 0x73, 0x3D, 0x54, 0x5F, 0xC1, 0x71,
  0x54, 0x3C, 0x55, 0xCD, 0xF6, 0x7B, 0x7D, 0x04, 0x37, 0xB5,
  0x0B, 0x4F, 0xBB, 0xFF, 0xB3, 0xB5, 0x2D, 0x08, 0x1E, 0x87,
  0x90, 0xC8, 0x4D, 0x6A, 0xF9, 0x49, 0xB3, 0x7D, 0xA3, 0xD0,
  0x63, 0xC4, 0x02, 0x94, 0x70, 0x25, 0x55, 0x5E, 0x1E, 0xCA,
  0xAF, 0x58, 0x90, 0x46, 0xAD, 0xAA, 0xB4, 0x83, 0x85, 0xD8,
  0x63, 0x15, 0x53, 0x06, 0x18, 0xC8, 0xB7, 0xC0, 0x94, 0x47,
  0x10, 0xF8, 0x87, 0xCD, 0xF5, 0x2B, 0x52, 0xE4, 0xCA, 0xC4,
  0x30, 0x05, 0x55, 0x19, 0xCA, 0x39, 0xE1, 0xEC, 0x59, 0x74,
  0x12, 0x8A, 0xA8, 0x6B, 0xFE, 0x9E, 0x18, 0x42, 0x54, 0x8B,
  0x29, 0x04, 0xA7, 0xCA, 0xF2, 0x94, 0x02, 0x77, 0xB6, 0x33,
  0x9B, 0xEA, 0x7A, 0x1A, 0x85, 0xEB, 0xED, 0xA3, 0x5A, 0x88,
  0x5F, 0xB6, 0x8A, 0x8A, 0xBD, 0x7B, 0xCC, 0x2B, 0xEC, 0x93,
  0x14, 0xAA, 0x17, 0x5A, 0xA1, 0x81, 0xE9, 0x49, 0x7F, 0xDF,
  0x0E, 0xB8, 0x94, 0x2D, 0x2D, 0xA2, 0x68, 0xB4, 0x75, 0xED,
  0xBA, 0xF3, 0x63, 0x9E, 0x99, 0x43, 0x88, 0x2C, 0x08, 0x4A,
  0x70, 0x7E, 0xE7, 0xD7, 0xFE, 0xDD, 0xAD, 0xC4, 0x79, 0x5C,
  0xFF, 0x34, 0x21, 0xB2, 0x0D, 0xC9, 0x72, 0xF0, 0xC6, 0x05,
  0x25, 0x6D, 0x43, 0xF6, 0xD7, 0x00, 0x7C, 0x1B, 0x7C, 0x64,
  0x1D, 0x03, 0xAD, 0x89, 0x1E, 0x33, 0x55, 0x08, 0xCC, 0x70,
  0x9F, 0xAC, 0x69, 0x37, 0x2D, 0x07, 0x02, 0xB8, 0xB7, 0x0D,
  0x2C, 0x77, 0xD7, 0x1D, 0x11, 0xF2, 0xFD, 0x3A, 0x80, 0x52,
  0xF1, 0x78, 0xEA, 0x03, 0xF2, 0xBE, 0x26, 0x4C, 0x69, 0xC1,
  0xE1, 0x37, 0xBA, 0x64, 0x8A, 0x6C, 0xDD, 0x2C, 0x78, 0x9B,
  0x06, 0x1A, 0x08, 0x26, 0xB6, 0x39, 0xD8, 0xCC, 0x2C, 0x92,
  0x66, 0xB3, 0x02, 0x86, 0x72, 0xD7, 0x1C, 0x0E, 0x56, 0xB9,
  0x23, 0x48, 0x48, 0xA2, 0xE0, 0xD3, 0x3D, 0xA2, 0x95, 0x0A,
  0xD5, 0x6C, 0xA8, 0x54, 0xCB, 0x47, 0xD5, 0x4C, 0x7C, 0xA5,
  0x23, 0x7E, 0x5C, 0xD2, 0xF3, 0x0A, 0x1C, 0xC9, 0xA9, 0x1E,
  0xBD, 0x8E, 0xE3, 0xF1, 0x06, 0xEF, 0xF5, 0xCA
};

const int MAX_N = 128;
int a[MAX_N][MAX_N + 1];

void exchange(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void exchange_row(int x, int y) {
    for (int i = 0; i <= MAX_N; ++i) {
        exchange(&a[x][i], &a[y][i]);
    }
}

void gaussian() {
    for (int i = 0; i < MAX_N; ++i) {
        if (!a[i][i]) {
            for (int j = i + 1; j < MAX_N; ++j) {
                if (a[j][i]) {
                    exchange_row(i, j);
                    break;
                }
            }
        }
        for (int j = i + 1; j < MAX_N; ++j) {
            if (!a[j][i]) {
                continue;
            }
            for (int k = i; k <= MAX_N; ++k) {
                a[j][k] ^= a[i][k];
            }
        }
    }
    for (int i = MAX_N - 1; i > 0; --i) {
        if (!a[i][i]) {
            continue;
        }
        for (int j = i - 1; j >= 0; --j) {
            if (a[j][i]) {
                a[j][i] ^= a[i][i];
                a[j][MAX_N] ^= a[i][MAX_N];
            }
        }
    }
}

void zapus_get(char s[]) {
    char *aim = s - 0x10;
    // aim = "\xF9\x89\x6E\x83\x19\x0F\xBF\x21\x24\x8C\x0D\x09\xA1\xFB\xA8\xFE";
    // aim = "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";

    for (int i = 0; i < 0x10; ++i) {
        for (int j = 0; j < 8; ++j) {
            a[i * 8 + j][MAX_N] = (aim[i] >> (7 - j)) & 1;
        }
    }
    for (int i = 0; i < 0x80; ++i) {
        for (int j = 0; j < 0x10; ++j) {
            for (int k = 0; k < 8; ++k) {
                a[i][j * 8 + k] = (ida_chars[i * 0x10 + j] >> (7 - k)) & 1;
            }
        }
    }
    gaussian();
    // for (int i = 0; i < MAX_N; ++i) {
    //     for (int j = 0; j <= MAX_N; ++j) {
    //         printf("%d", a[i][j]);
    //     }
    //     printf("\n");
    // }
    for (int i = 0; i < 0x10; ++i) {
        s[i] = 0;
        for (int j = 0; j < 8; ++j) {
            s[i] = s[i] << 1 | a[i * 8 + j][MAX_N];
        }
        // printf("%#x\n", s[i]);
    }
    // printf("crc: %#x\n", (*(int *)aim));
    doit(*(int *)aim);
    // doit(3069720756UL);
    // memcpy(s, (int)s - 0x10, 16);
}

