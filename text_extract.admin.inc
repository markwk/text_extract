<?php
/**
 * @file
 * Admin settings for text extraction.
 */
/**
 *
 * Text extraction settings form.
 */
function text_extraction_form_settings() {
  $form['extract_content_type'] = array(
    '#type' => 'checkboxes',
    '#title' => t("Content Type"),
    '#default_value' => variable_get('extract_content_type', array()),
    '#options' => text_extract_get_content_types(),
  );
  $form['extract_content_number'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('extract_content_number', FALSE),
    '#title' => t("Number of docs per cron run"),
    '#size' => 3,
  );
  $form['extract_content_location'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('extract_content_location', 'java -jar /usr/java/jre1.7.0_02/lib/tika-app-1.0.jar  -t'),
    '#title' => t("Tika location path"),
    '#size' => 70,
  );
  $form['extract_content_htmlbefore'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('extract_content_htmlbefore', '<b>Text automatically extracted from attachment below. Please download attachment to view properly formatted document.</b>'),
    '#title' => t("HTML before extracted body"),
    '#rows' => 4,
  );
  $form['extract_content_htmlafter'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('extract_content_htmlafter', ''),
    '#title' => t("HTML before extracted body"),
    '#rows' => 4,
  );
  $form['extract_during_cron'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('extract_during_cron', FALSE),
    '#title' => t('Extract the selected content types during Cron Run'),
  );
  return system_settings_form($form);
}
/**
 * Getting list of content types for configuration settings
 *
 * @return
 *   array of content types.
 */
function text_extract_get_content_types() {
  $result = node_type_get_types();
  foreach ($result as $type => $value) {
    $content_types[$type] = $value->name;
  }
  return $content_types;
}
